#include <iostream>

#include "logger.hpp"

using namespace std;

void report_error(int line, string where, string message, dih::dihManager& manager) {
    cerr << "[line " << line << "] Error" << where << ": " << message << endl;
    manager.had_error = true;
}

namespace dih {
    namespace logger {

        void error(int line, string message, dihManager& manager) {
            report_error(line, "", message, manager);
        }
        void error(const Token& token, const string& message, dihManager& manager) {
            if (token.getType() == Token::Type::T_EOF) {
                report_error(token.getLine(), " at end", message, manager);
            }
            else {
                report_error(token.getLine(), " at '" + token.getLexeme() + "'", message, manager);
            }
        }

        void runtimeError(const types::RuntimeError& error, dihManager& manager) {
            if (error.token.getLine() > 0) {
                cerr << "[line " << error.token.getLine() << " ]";
            }
            cerr << "Runtime error: " << error.what() << endl;
            manager.had_runtime_error = true;
        }
    } // namespace logger
} // namespace dih