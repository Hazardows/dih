#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <filesystem>
#include <cctype>

static std::string toLower(const std::string& s) {
    std::string res = s;
    std::transform(res.begin(), res.end(), res.begin(), ::tolower);
    return res;
}

class GenerateAst {
public:
    static void defineAst(const std::string& outputDir,
                         const std::string& baseName,
                         const std::vector<std::string>& types) {
        std::string path = outputDir + "/" + baseName + ".hpp";
        std::ofstream writer(path);
        if (!writer) {
            std::cerr << "Error: Could not create file " << path << std::endl;
            return;
        }

        writer << "#pragma once\n\n";
        writer << "#include <memory>\n";
        writer << "#include <string>\n";
        writer << "#include <vector>\n\n";

        std::string visitor_ret = "dih::special::dihValueContainer";

        // Incluir cabeceras necesarias
        if (baseName == "Expr") {
            writer << "#include \"../token/token.hpp\"\n";
        }
        if (baseName == "Stmt") {
            writer << "#include \"expr.hpp\"\n";
            writer << "#include \"typeid.hpp\"\n";
            visitor_ret = "void";
        }
        writer << "#include \"../types.hpp\"\n\n";

        std::string ns = "dih::" + toLower(baseName);
        writer << "namespace " << ns << " {\n\n";

        // Forward declarations
        for (const auto& type : types) {
            std::string className = type.substr(0, type.find(':'));
            trim(className);
            writer << "    class " << className << ";\n";
        }
        writer << "\n";

        // Visitor interface
        defineVisitor(writer, types, visitor_ret);

        // Clase base
        writer << "    class " << baseName << " {\n\n";
        writer << "        public:\n";
        writer << "        virtual ~" << baseName << "() = default;\n\n";
        writer << "        virtual " + visitor_ret + " accept(Visitor& visitor) const = 0;\n";
        writer << "    };\n\n";

        // Generar cada nodo
        for (const auto& type : types) {
            defineType(writer, baseName, type, visitor_ret);
        }

        writer << "} // namespace " << ns << "\n";
        writer.close();
        std::cout << "Generated: " << path << std::endl;
    }

private:
    static void trim(std::string& s) {
        s.erase(0, s.find_first_not_of(" \t"));
        s.erase(s.find_last_not_of(" \t") + 1);
    }

    static void defineVisitor(std::ofstream& writer,
                             const std::vector<std::string>& types, std::string& visitor_ret) {
        writer << "    class Visitor {\n\n";
        writer << "        public:\n";
        writer << "        virtual ~Visitor() = default;\n";
        for (const auto& type : types) {
            std::string typeName = type.substr(0, type.find(':'));
            trim(typeName);
            writer << "        virtual "+ visitor_ret +" visit" << typeName
                   << "(const " << typeName << "& node) = 0;\n";
        }
        writer << "    };\n\n";
    }

    static std::string sanitizeName(const std::string& name) {
        if (name == "operator") return "op";
        if (name == "class") return "class_";
        if (name == "virtual") return "virtual_";
        if (name == "private") return "private_";
        if (name == "protected") return "protected_";
        if (name == "public") return "public_";
        if (name == "default") return "default_";
        if (name == "delete") return "delete_";
        if (name == "new") return "new_";
        if (name == "typename") return "typename_";
        return name;
    }

    static void defineType(std::ofstream& writer,
                          const std::string& baseName,
                          const std::string& typeDef, std::string& visitor_ret) {
        size_t colonPos = typeDef.find(':');
        std::string className = typeDef.substr(0, colonPos);
        trim(className);
        std::string fieldList = typeDef.substr(colonPos + 1);
        trim(fieldList);

        std::vector<std::pair<std::string, std::string>> fields;
        std::stringstream ss(fieldList);
        std::string field;
        while (std::getline(ss, field, ',')) {
            trim(field);
            size_t spacePos = field.find(' ');
            if (spacePos != std::string::npos) {
                std::string type = field.substr(0, spacePos);
                std::string name = field.substr(spacePos + 1);
                trim(type);
                trim(name);
                name = sanitizeName(name);
                fields.emplace_back(type, name);
            }
        }

        // Convertir tipos Java a C++
        auto convertType = [&](const std::string& javaType) -> std::string {
            if (javaType == "Expr") return "std::unique_ptr<expr::Expr>";   // fijo
            if (javaType == "Stmt") return "std::unique_ptr<stmt::Stmt>";   // fijo
            if (javaType == "Token") return "Token";
            if (javaType == "Object") return "types::var_t";
            return javaType;
        };

        writer << "    class " << className << " : public " << baseName << " {\n\n";
        writer << "        public:\n";

        // Constructor
        writer << "        " << className << "(";
        for (size_t i = 0; i < fields.size(); ++i) {
            const auto& [type, name] = fields[i];
            std::string cppType = convertType(type);
            writer << cppType << " " << name;
            if (i + 1 < fields.size()) writer << ", ";
        }
        writer << ")\n";
        writer << "        : ";
        for (size_t i = 0; i < fields.size(); ++i) {
            const auto& [type, name] = fields[i];
            if (convertType(type).find("unique_ptr") != std::string::npos) {
                writer << name << "(std::move(" << name << "))";
            } else {
                writer << name << "(" << name << ")";
            }
            if (i + 1 < fields.size()) writer << ", ";
        }
        writer << " {}\n\n";

        // accept
        writer << "        " + visitor_ret + " accept(Visitor& visitor) const override {\n";
        writer << "            return visitor.visit" << className << "(*this);\n";
        writer << "        }\n\n";

        // Campos
        writer << "        // Fields\n";
        for (const auto& [type, name] : fields) {
            std::string cppType = convertType(type);
            writer << "        " << cppType << " " << name << ";\n";
        }
        writer << "    };\n\n";
    }
};

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: generate_ast <output directory>" << std::endl;
        return 64;
    }
    std::string outDir = argv[1];
    std::filesystem::create_directories(outDir);

    GenerateAst::defineAst(outDir, "Expr", {
        "Assign   : Token name, Expr value",
        "Binary   : Expr left, Token operator, Expr right",
        "Call     : Expr callee, Token paren, std::vector<std::unique_ptr<expr::Expr>> arguments",
        "Grouping : Expr expression",
        "Increment: Token op, Token name, bool isPrefix",
        "Literal  : Object value",
        "Logical  : Expr left, Token operator, Expr right",
        "Unary    : Token operator, Expr right",
        "Variable : Token name"
    });

    GenerateAst::defineAst(outDir, "Stmt", {
        "Block      : std::vector<std::unique_ptr<Stmt>> statements",
        "Expression : Expr expression",
        "Return     : Token keyword, Expr value",
        "Function   : Token name, std::vector<Token> params, std::vector<std::unique_ptr<stmt::Stmt>> body",
        "If         : Expr condition, Stmt thenBranch, Stmt elseBranch",
        "Var        : Token name, Expr initializer",
        "VarList    : std::vector<std::unique_ptr<Var>> variables, dihTypeId type_id",
        "While      : Expr condition, Stmt body"
    });

    return 0;
}