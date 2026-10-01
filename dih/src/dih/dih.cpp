#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <cstdlib>

#include <memory>

#include "dih.hpp"

#include "core/token/tokenizer.hpp"
#include "core/parser/parser.hpp"
#include "core/ast/ast_printer.hpp"

#include "interpreter/interpreter.hpp"

using namespace std;

static void run(string, dih::dihManager&);

namespace dih {
    
    void run_file(string path, dihManager& manager) {
        ifstream file(path);

        stringstream buffer;
        buffer << file.rdbuf();

        run(buffer.str(), manager);
        manager = {};
    }

    void run_code(string code, dihManager& manager) {
        run(code, manager);
        manager = {};
    }

    void run_prompt(dihManager& manager) {
        cout << "hi from dih console!" << endl;

        string line;
        while (std::cin) {
            cout << "> ";
            cout.flush();
        
            if (getline(std::cin, line)) {
                if (!line.empty()) {
                    run(line, manager);
                    manager = {};
                }
            }
            else {
                break;
            }
        }
    
        cout << endl;
    }
}

// actual run code
static void run(string source, dih::dihManager& manager) {
    if (source.empty()) {
        return;
    }

    dih::Tokenizer scanner(source, manager);
    vector<dih::Token> tokens = scanner.scanTokens();

    if (manager.had_error) {
        return;
    }

    // Print the tokens
    // cout << "tokens:\n";
    // for (const auto& token : tokens) {
    //     if (token.getType() != dih::Token::Type::T_EOF) {
    //         cout << token << endl;
    //     }
    // }

    dih::parser::Parser parser(tokens, manager);
    vector<unique_ptr<dih::stmt::Stmt>> statements = parser.parse();

    if (manager.had_error) {
        return;
    }

    // Print ast
    // NOTE: no ast printer for stmt
    // cout << "ast:\n";
    // dih::AstPrinter printer;
    // cout << printer.print(*statements) << endl;

    // cout << "interpreter:\n";
    dih::dihi interp;
    interp.interpret(statements, manager);

    if (manager.had_runtime_error) {
        exit(70);
    }
}