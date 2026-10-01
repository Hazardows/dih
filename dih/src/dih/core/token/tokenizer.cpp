#include <cctype>
#include <iostream>

#include "tokenizer.hpp"

using namespace std;

namespace dih {

    Tokenizer::Tokenizer(const string& source, dihManager& dmanager)
        : source(source), manager(dmanager) {
        keywords = {
            {"and", Token::Type::T_AND},
            {"class", Token::Type::T_CLASS},
            {"else", Token::Type::T_ELSE},
            {"false", Token::Type::T_FALSE},
            {"for", Token::Type::T_FOR},
            {"func", Token::Type::T_FUNC},
            {"if", Token::Type::T_IF},
            {"nil", Token::Type::T_NIL},
            {"null", Token::Type::T_NULL},
            {"or", Token::Type::T_OR},
            // {"print", Token::Type::T_PRINT},
            {"return", Token::Type::T_RETURN},
            {"super", Token::Type::T_SUPER},
            {"this", Token::Type::T_THIS},
            {"true", Token::Type::T_TRUE},
            {"while", Token::Type::T_WHILE},
            {"var", Token::Type::T_TYPE_VAR},
            {"string", Token::Type::T_TYPE_STRING},
            {"bool", Token::Type::T_TYPE_BOOL},
            {"char", Token::Type::T_TYPE_CHAR},
            {"int", Token::Type::T_TYPE_I64},
            {"float", Token::Type::T_TYPE_F32},
            {"double", Token::Type::T_TYPE_F64},
            {"u8", Token::Type::T_TYPE_U8},
            {"u16", Token::Type::T_TYPE_U16},
            {"u32", Token::Type::T_TYPE_U32},
            {"u64", Token::Type::T_TYPE_U64},
            {"i8", Token::Type::T_TYPE_I8},
            {"i16", Token::Type::T_TYPE_I16},
            {"i32", Token::Type::T_TYPE_I32},
            {"i64", Token::Type::T_TYPE_I64},
            {"f32", Token::Type::T_TYPE_F32},
            {"f64", Token::Type::T_TYPE_F64},
            {"void", Token::Type::T_TYPE_VOID}
        };
    }

    bool Tokenizer::isAtEnd() {
        return current >= source.size();
    }

    char Tokenizer::advance() {
        return source[current++];
    }

    void Tokenizer::addToken(Token::Type type) {
        string text = source.substr(start, current - start);
        tokens.emplace_back(type, text, line);
    }

    void Tokenizer::addToken(Token::Type type, types::var_t literal) {
        string text = source.substr(start, current - start);
        tokens.emplace_back(type, text, line, literal);
    }

    bool Tokenizer::match(char expected) {
        if (isAtEnd()) return false;
        if (source[current] != expected) return false;
        current++;
        return true;
    }

    char Tokenizer::peek() {
        if (isAtEnd()) return '\0';
        return source[current];
    }

    char Tokenizer::peekNext() {
        if (current + 1 >= source.length()) return '\0';
        return source[current + 1];
    }

    void Tokenizer::add_string() {
        std::string value;
        bool escaped = false;

        while (!isAtEnd()) {
            char c = advance();
        
            if (escaped) {
                switch (c) {
                    case '\\': value += '\\'; break;
                    case '\'': value += '\''; break;
                    case '"':  value += '"';  break;
                    case 'n':  value += '\n'; break;
                    case 'r':  value += '\r'; break;
                    case 't':  value += '\t'; break;
                    default:
                        dih::logger::error(line, "Unknown escape sequence: \\" + std::string(1, c), manager);
                        return;
                }
                escaped = false;
            }
            else if (c == '\\') {
                escaped = true;
            }
            else if (c == '"') {
                break;
            }
            else {
                if (c == '\n') line++;
                value += c;
            }
        }

        if (isAtEnd()) {
            dih::logger::error(line, "Unterminated string", manager);
            return;
        }

        addToken(Token::Type::T_STRING, value);
    }

    void Tokenizer::add_char() {
        char value = '\0';
        bool escaped = false;
        bool done = false;

        while (!isAtEnd() && !done) {
            char c = advance();
            if (!escaped && c == '\\') {
                escaped = true;
                continue;
            }
            if (escaped) {
                switch (c) {
                    case '\\': value = '\\'; break;
                    case '\'': value = '\''; break;
                    case 'n': value = '\n'; break;
                    case 'r': value = '\r'; break;
                    case 't': value = '\t'; break;
                    default:
                        dih::logger::error(line, "Unknown escape sequence", manager);
                        return;
                }
                escaped = false;
                if (peek() != '\'') {
                    dih::logger::error(line, "Expected closing quote after escape", manager);
                    while (!isAtEnd() && peek() != '\'') {
                        advance();
                    }
                    if (!isAtEnd()) {
                        advance();
                    }
                    return;
                }
                advance(); // consume closing quote
                done = true;
            }
            else if (c == '\'') {
                // closing quote directly
                done = true;
            }
            else {
                if (value != '\0') {
                    dih::logger::error(line, "Too many characters in character literal", manager);
                    while (!isAtEnd() && peek() != '\'') {
                        advance();
                    }
                    if (!isAtEnd()) {
                        advance();
                    }
                    return;
                }
                value = c;
            }
        }

        if (!done) {
            dih::logger::error(line, "Unterminated character literal", manager);
            return;
        }
        if (value == '\0') {
            dih::logger::error(line, "Empty character literal", manager);
            advance();
            return;
        }

        addToken(Token::Type::T_CHAR, value);
    }

    void Tokenizer::add_number() {
        while (isdigit(peek())) advance();

        if (peek() == '.' && isdigit(peekNext())) {
            advance(); // consume '.'
            while (isdigit(peek())) advance();
        }

        double value = stod(source.substr(start, current - start));
        addToken(Token::Type::T_NUMBER, value);
    }

    void Tokenizer::add_identifier() {
        while (isalnum(peek()) || peek() == '_') advance();

        string text = source.substr(start, current - start);
        auto it = keywords.find(text);
        Token::Type type = (it != keywords.end()) ? it->second : Token::Type::T_IDENTIFIER;
        addToken(type);
    }

    void Tokenizer::scanToken() {
        char c = advance();

        switch (c) {
            case '(':
                addToken(Token::Type::T_LEFT_PARENT);
                break;
            case ')':
                addToken(Token::Type::T_RIGHT_PARENT);
                break;
            case '{':
                addToken(Token::Type::T_LEFT_BRACE);
                break;
            case '}':
                addToken(Token::Type::T_RIGHT_BRACE);
                break;
            case ',':
                addToken(Token::Type::T_COMMA);
                break;
            case '.':
                addToken(Token::Type::T_DOT);
                break;
            case '-': {
                Token::Type token = Token::Type::T_MINUS;
                if (match('-')) {
                    token = Token::Type::T_MINUS_MINUS;
                }
                else if (match('=')) {
                    token = Token::Type::T_MINUS_EQUAL;
                }
                addToken(token);
                break;
            }
            case '+': {
                Token::Type token = Token::Type::T_PLUS;
                if (match('+')) {
                    token = Token::Type::T_PLUS_PLUS;
                }
                else if (match('=')) {
                    token = Token::Type::T_PLUS_EQUAL;
                }
                addToken(token);
                break;
            }
            case ';':
                addToken(Token::Type::T_SEMICOLON);
                break;
            case '&': {
                Token::Type token = Token::Type::T_AMPERSAND;
                if (match('&')) {
                    token = Token::Type::T_AND;
                }
                addToken(token);
                break;
            }
            case '|': {
                if (match('|')) {
                    addToken(Token::Type::T_OR);
                }
                else {
                    dih::logger::error(line, "Unexpected '|'", manager);
                }
                break;
            }
            case '*': {
                Token::Type token = Token::Type::T_ASTERISK;
                if (match('*')) {
                    if (match('=')) {
                        token = Token::Type::T_ASTERISK_ASTERISK_EQUAL;
                    }
                    else {
                        token = Token::Type::T_ASTERISK_ASTERISK;
                    }
                }
                else if (match('=')) {
                    token = Token::Type::T_ASTERISK_EQUAL;
                }
                addToken(token);
                break;
            }
            case '!':
                addToken(match('=') ? Token::Type::T_BANG_EQUAL : Token::Type::T_BANG);
                break;
            case '=':
                addToken(match('=') ? Token::Type::T_EQUAL_EQUAL : Token::Type::T_EQUAL);
                break;
            case '<':
                addToken(match('=') ? Token::Type::T_LESS_EQUAL : Token::Type::T_LESS);
                break;
            case '>':
                addToken(match('=') ? Token::Type::T_GREATER_EQUAL : Token::Type::T_GREATER);
                break;
            case '/':
                if (match('/')) {
                    // comment hasta fin de línea
                    while (peek() != '\n' && !isAtEnd()) advance();
                }
                else {
                    addToken(match('=') ? Token::Type::T_SLASH_EQUAL : Token::Type::T_SLASH);
                }
                break;
            case ' ':
            case '\r':
            case '\t':
                break;
            case '\n':
                line++;
                break;
            case '"':
                add_string();
                break;
            case '\'':
                add_char();
                break;
            default:
                if (isdigit(c)) {
                    add_number();
                }
                else if (isalpha(c) || c == '_') {
                    add_identifier();
                }
                else {
                    dih::logger::error(line, "Unexpected character.", manager);
                }
                break;
        }
    }

    vector<Token> Tokenizer::scanTokens() {
        while (!isAtEnd()) {
            start = current;
            scanToken();
        }
        tokens.emplace_back(Token::Type::T_EOF, "", line);
        return tokens;
    }
} // namespace dih