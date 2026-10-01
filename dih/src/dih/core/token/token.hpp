#pragma once

#include <string>
#include <iostream>

#include "../platform.h"
#include "../types.hpp"

namespace dih {
    
    class DIH_API Token {
        
        public:
        enum class Type {
            // Single-character tokens
            T_LEFT_PARENT, T_RIGHT_PARENT, T_LEFT_BRACE, T_RIGHT_BRACE,
            T_COMMA, T_DOT, T_SEMICOLON, T_AMPERSAND,
            
            // Asterisk
            // One or two character tokens
            T_MINUS, T_MINUS_MINUS, T_MINUS_EQUAL,
            T_PLUS, T_PLUS_PLUS, T_PLUS_EQUAL,
            T_ASTERISK, T_ASTERISK_EQUAL,
            T_ASTERISK_ASTERISK, T_ASTERISK_ASTERISK_EQUAL,
            T_SLASH, T_SLASH_EQUAL,
            T_BANG, T_BANG_EQUAL,
            T_EQUAL, T_EQUAL_EQUAL,
            T_GREATER, T_GREATER_EQUAL,
            T_LESS, T_LESS_EQUAL,

            // Literals
            T_IDENTIFIER, T_STRING, T_NUMBER, T_CHAR,
            
            // Keywords
            T_AND, T_CLASS, T_ELSE, T_FALSE, T_FUNC, T_FOR, T_IF, T_NIL, T_NULL, T_OR,
            T_RETURN, T_SUPER, T_THIS, T_TRUE, T_WHILE,

            // Types
            T_TYPE_VAR, T_TYPE_STRING, T_TYPE_BOOL, T_TYPE_CHAR,
            T_TYPE_U8, T_TYPE_U16, T_TYPE_U32, T_TYPE_U64,
            T_TYPE_I8, T_TYPE_I16, T_TYPE_I32, T_TYPE_I64,
            T_TYPE_F32, T_TYPE_F64, T_TYPE_VOID,

            T_EOF
        };
        
        Token(Type type, const std::string& lexeme, int line);
        Token(Type type, const std::string& lexeme, int line, const types::var_t literal);
        
        friend std::ostream& operator<<(std::ostream& os, const Token& token);
        
        std::string typeToString() const;

        Type getType() const;
        std::string getLexeme() const;
        types::var_t get() const;
        int getLine() const;

        private:
        Type type;
        std::string lexeme;
        int line;
        types::var_t literal;
    };
} // namespace dih