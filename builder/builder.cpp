#include <iostream>
#include <string>
#include <vector>
#include <filesystem>
#include <algorithm>
#include <sstream>
#include <cstring>

using namespace std;
namespace fs = filesystem;

#define CXX_COMPILER "clang++"
#define C_COMPILER "clang"
#define LINKER CXX_COMPILER

enum source_file_extension {
    cpp, cc, c, cxx, unknown
};

source_file_extension get_extension(const string& file) {
    size_t point_pos = file.find_last_of('.');
    if (point_pos == string::npos) {
        return unknown;
    }

    string ext_substr = file.substr(point_pos + 1);
    transform(ext_substr.begin(), ext_substr.end(), ext_substr.begin(), ::tolower);
    
    if (ext_substr == "c") {
        return c;
    }
    else if (ext_substr == "cc") {
        return cc;
    }
    else if (ext_substr == "cxx") {
        return cxx;
    }
    else if (ext_substr == "cpp") {
        return cpp;
    }
    
    return unknown;
}

vector <fs::path> o_paths;
bool compile_to_o(const string& file, const fs::path& obj_base_dir, const string& compiler_flags, const string& defines, const string& include_flags) {
    source_file_extension ext = get_extension(file);
    
    if (ext == unknown) {
        cerr << "Warning: Unknown extension for file: " << file << endl;
        return false;
    }
    
    string compiler = (ext == c || ext == cc) ? C_COMPILER : CXX_COMPILER;
    fs::path source_path(file);
    string obj_name = source_path.stem().string() + ".o";
    
    // Mantener estructura de directorios relativa
    fs::path relative_path = fs::relative(source_path.parent_path(), fs::current_path());
    fs::path obj_dir = obj_base_dir / relative_path;
    
    fs::path full_obj_path = obj_dir / obj_name;
    fs::create_directories(obj_dir);
    
    string standard = (compiler == CXX_COMPILER) ? "-std=c++23" : "-std=c23";
    string command = compiler + " -c " + file + " -o " + full_obj_path.string() + " " + 
                     compiler_flags + " " + standard + " " + defines + " " + include_flags;
    
    cout << "Compiling " << source_path.string() << "..." << endl;
    int result = system(command.c_str());
    if (result != 0) {
        cerr << "Error compiling: " << file << endl;
        return false;
    }
    o_paths.push_back(full_obj_path);
    return true;
}

bool link_objects(const vector<fs::path>& obj_files, const fs::path& output_dir, const string& output_name, const string& linker_flags) {
    if (obj_files.empty()) {
        cerr << "Error: No object files to link." << endl;
        return false;
    }
    
    fs::create_directories(output_dir);
    fs::path output_path = output_dir / output_name;
    
    string link_command = string(LINKER) + " ";
    for (const auto& obj_file : obj_files) {
        link_command += obj_file.string() + " ";
    }
    
    link_command += "-o " + output_path.string() + " " + linker_flags;
    
    // Opcional: agregar flags adicionales
    // link_command += " -Wall -O2";  // Flags de optimización
    // link_command += " -lm";         // Linkear con math library
    // link_command += " -pthread";    // Linkear con pthreads
    
    cout << "Linking " << obj_files.size() << " object files..." << endl;
    // cout << "Command: " << link_command << endl;
    
    int result = system(link_command.c_str());
    if (result != 0) {
        cerr << "Error: Linking failed with exit code " << result << endl;
        return false;
    }
    cout << "Successfully created: " << output_path << endl;
    return true;
}

void scan_source_files(const string& directory, vector<string>& src_files) {
    try {
        for (const auto& entry : fs::recursive_directory_iterator(directory)) {
            if (fs::is_regular_file(entry.path())) {
                string extension = entry.path().extension().string();
                transform(extension.begin(), extension.end(), extension.begin(), ::tolower);
                
                if (extension == ".cpp" || extension == ".cc" || extension == ".c" || extension == ".cxx") {
                    src_files.push_back(entry.path().string());
                    // cout << "Found source file: " << entry.path().string() << endl;
                }
            }
        }
    } catch (const fs::filesystem_error& e) {
        cerr << "Error accessing directory: " << e.what() << endl;
    }
}

void print_help() {
    cout << "usage: builder mode arguments" << endl;
    cout << endl;
    cout << "modes:" << endl;
    cout << "   build -> builds a prooject with te specified arguments.";
    cout << "       arguments:" << endl;
    cout << "           $(src_dir)" << endl;
    cout << "           $(build_dir)" << endl;
    cout << "           $(build_name)" << endl;
    cout << "           [$(compiler_flags)]" << endl;
    cout << "           [$(defines)]" << endl;
    cout << "           [$(include_flags)]" << endl;
    cout << "           [$(linker_flags)]" << endl;
    cout << "   clean -> cleans a previous build.";
    cout << "       arguments:" << endl;
    cout << "           $(build_dir)" << endl;
    cout << "           $(build_name)" << endl;
    cout << "optional arguments are signaled with [] and can be specified as 'none' to be skipped" << endl;
    cout << endl;
    cout << "Examples:" << endl;
    cout << "   builder build ./src ./build myapp" << endl;
    cout << "   builder build ./src ./build myapp \"-Wall -O2\" \"-DDEBUG\" \"-I./include\" \"-lm\"" << endl;
    cout << "   builder build ./src ./build myapp \"-Wall\" none none \"-pthread\"" << endl;
    cout << "builder clean ./build myapp" << endl;
}

vector<string> parse_quoted_args(int argc, char* argv[], int start_index) {
    vector<string> args;
    for (int i = start_index; i < argc; i++) {
        string arg = argv[i];
        
        if (arg.front() == '"') {
            // Argumento entre comillas
            if (arg.back() == '"') {
                // Está completo en un solo argumento
                arg = arg.substr(1, arg.length() - 2);
                args.push_back(arg);
            } else {
                // Multilínea o con espacios
                string combined = arg.substr(1);
                i++;
                while (i < argc) {
                    if (argv[i][strlen(argv[i]) - 1] == '"') {
                        combined += " " + string(argv[i]).substr(0, strlen(argv[i]) - 1);
                        break;
                    } else {
                        combined += " " + string(argv[i]);
                    }
                    i++;
                }
                args.push_back(combined);
            }
        } else {
            // Argumento normal sin comillas
            args.push_back(arg);
        }
    }
    return args;
}

void remove_directory_contents(const fs::path& dir) {
    if (!fs::exists(dir)) return;
    
    for (const auto& entry : fs::directory_iterator(dir)) {
        if (fs::is_directory(entry.path())) {
            // Recursivamente eliminar subdirectorios
            remove_directory_contents(entry.path());
            fs::remove(entry.path());
            return;
        }

        // Eliminar archivos
        fs::remove(entry.path());
        cout << "Removed file: " << entry.path() << endl;
    }
}

int perform_build(int argc, char* argv[]) {
    vector<string> args = parse_quoted_args(argc, argv, 2);

    string src_dir = args[0];
    string build_dir = args[1];
    string build_name = args[2];
    string compiler_flags = args.size() > 0 ? args[3] : "";
    string defines = args.size() > 1 ? args[4] : "";
    string include_flags = args.size() > 2 ? args[5] : "";
    string linker_flags = args.size() > 3 ? args[6] : "";

    // Reemplazar "none"
    if (compiler_flags == "none") compiler_flags = "";
    if (defines == "none") defines = "";
    if (include_flags == "none") include_flags = "";
    if (linker_flags == "none") linker_flags = "";
    
    vector<string> src_files;
    if (!fs::exists(src_dir) || !fs::is_directory(src_dir)) {
        cerr << "Error: Source directory '" << src_dir << "' does not exist or is not a directory." << endl;
        return 1;
    }

    if (!fs::exists(build_dir)) {
        if (fs::create_directories(build_dir)) {
            cout << "Created export directory: " << build_dir << endl;
        }
        else {
            cerr << "Error: Could not create export directory: " << build_dir << endl;
            return 1;
        }
    }

    auto obj_dir = fs::path(build_dir).append("obj");
    if (!fs::exists(obj_dir)) {
        if (!fs::create_directories(obj_dir)) {
            cerr << "Error: Failed to create obj dir: " << obj_dir.string() << endl;
        }
    }
    
    cout << "Scanning source directory: " << src_dir << endl;
    scan_source_files(src_dir, src_files);
    
    cout << "Found " << src_files.size() << " source files" << endl;
    for (string& file : src_files) {
        if (!compile_to_o(file, obj_dir, compiler_flags, defines, include_flags)) {
            return -1;
        }
    }

    if (!link_objects(o_paths, build_dir, build_name, linker_flags)) {
        return -2;
    }
    
    return 0;
}

int perform_clean(int argc, char* argv[]) {
    vector<string> args = parse_quoted_args(argc, argv, 2);

    string build_dir = args[0];
    string build_name = args[1];

    fs::path build_path(build_dir);

    if (fs::exists(build_path / build_name)) {
        fs::remove(build_path / build_name);
    }

    fs::path obj_dir = build_path / "obj"; 
    if (fs::exists(obj_dir)) {
        remove_directory_contents(obj_dir);
        fs::remove(obj_dir); // Eliminar el directorio obj vacío
        cout << "Removed directory: " << obj_dir << endl;
    }

    return 0;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        print_help();
        return 1;
    }

    if (string(argv[1]) == "build") {
        if (argc < 5) {
            cout << "builder error: not enough arguments were provided for building." << endl;
            print_help();
            return -3;
        }
        perform_build(argc, argv);
    }
    else if (string(argv[1]) == "clean") {
        if (argc < 4) {
            cout << "builder error: not enough arguments were provided for cleaning." << endl;
            print_help();
            return -3;
        }
        perform_clean(argc, argv);
    }
}