#pragma once

#include <string>

#include "../../dih.hpp"
#include "../token/token.hpp"

namespace dih {
    namespace logger {
        namespace types {
            
            class RuntimeError : public std::runtime_error {
                public:
                Token token;

                RuntimeError(const Token& token, const std::string message)
                    : std::runtime_error(message), token(token) {}

                RuntimeError(const std::string message)
                    : std::runtime_error(message), token(Token::Type::T_IDENTIFIER, "", -1) {}
            };
        }

        void error(int line, std::string message, dihManager& manager);
        void error(const Token& token, const std::string& message, dihManager& manager);
        
        void runtimeError(const types::RuntimeError& error, dihManager& manager);
    } // namespace logger
} // namespace dih