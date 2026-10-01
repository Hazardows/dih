#pragma once

#include <vector>
#include <unordered_map>
#include <iostream>

#include "token.hpp"
#include "../logger/logger.hpp"

namespace dih {

    class Tokenizer {

        public:
        Tokenizer(const std::string& source, dihManager& dmanager);
        std::vector<Token> scanTokens();

        private:
        std::string source;
        std::vector<Token> tokens;
        size_t start = 0;
        size_t current = 0;
        size_t line = 1;
        dihManager& manager;

        std::unordered_map<std::string, Token::Type> keywords;

        bool isAtEnd();
        char advance();
        void addToken(Token::Type type);
        void addToken(Token::Type type, types::var_t literal);
        bool match(char expected);
        char peek();
        char peekNext();
        void add_string();
        void add_char();
        void add_number();
        void add_identifier();
        void scanToken();
    };
} // namespace dih