#include "token.hpp"

using namespace std;

namespace dih {
        
        Token::Token(Type type, const string& lexeme, int line) 
            : type(type), lexeme(lexeme), line(line) {}
        
        Token::Token(Type type, const std::string& lexeme, int line, const types::var_t literal)
            : type(type), lexeme(lexeme), line(line), literal(literal) {}
        
        ostream& operator<<(ostream& os, const Token& token) {
            os << "Token(" << token.typeToString() 
               << ", '" << token.lexeme << "', line " << token.line << ")";
            return os;
        }
        
        string Token::typeToString() const {
            switch (type) {
                case Type::T_LEFT_PARENT:               return "LEFT_PARENT";
                case Type::T_RIGHT_PARENT:              return "RIGHT_PARENT";
                case Type::T_LEFT_BRACE:                return "LEFT_BRACE";
                case Type::T_RIGHT_BRACE:               return "RIGHT_BRACE";
                case Type::T_COMMA:                     return "COMMA";
                case Type::T_DOT:                       return "DOT";
                case Type::T_SEMICOLON:                 return "SEMICOLON";
                case Type::T_AMPERSAND:                 return "AMPERSAND";
                case Type::T_MINUS:                     return "MINUS";
                case Type::T_MINUS_MINUS:               return "MINUS_MINUS";
                case Type::T_MINUS_EQUAL:               return "MINUS_EQUAL";
                case Type::T_PLUS:                      return "PLUS";
                case Type::T_PLUS_PLUS:                 return "PLUS_PLUS";
                case Type::T_PLUS_EQUAL:                return "PLUS_EQUAL";
                case Type::T_ASTERISK:                  return "ASTERISK";
                case Type::T_ASTERISK_EQUAL:            return "ASTERISK_EQUAL";
                case Type::T_ASTERISK_ASTERISK:         return "ASTERISK_ASTERISK";
                case Type::T_ASTERISK_ASTERISK_EQUAL:   return "ASTERISK_ASTERISK_EQUAL";
                case Type::T_SLASH:                     return "SLASH";
                case Type::T_BANG:                      return "BANG";
                case Type::T_EQUAL:                     return "EQUAL";
                case Type::T_BANG_EQUAL:                return "BANG_EQUAL";
                case Type::T_EQUAL_EQUAL:               return "EQUAL_EQUAL";
                case Type::T_GREATER:                   return "GREATER";
                case Type::T_GREATER_EQUAL:             return "GREATER_EQUAL";
                case Type::T_LESS:                      return "LESS";
                case Type::T_LESS_EQUAL:                return "LESS_EQUAL";
                case Type::T_IDENTIFIER:                return "IDENTIFIER";
                case Type::T_STRING:                    return "STRING";
                case Type::T_CHAR:                      return "CHAR";
                case Type::T_NUMBER:                    return "NUMBER";
                case Type::T_AND:                       return "AND";
                case Type::T_CLASS:                     return "CLASS";
                case Type::T_ELSE:                      return "ELSE";
                case Type::T_FALSE:                     return "FALSE";
                case Type::T_FUNC:                      return "FUNC";
                case Type::T_FOR:                       return "FOR";
                case Type::T_IF:                        return "IF";
                case Type::T_NIL:                       return "NIL";
                case Type::T_NULL:                      return "NULL";
                case Type::T_OR:                        return "OR";
                case Type::T_RETURN:                    return "RETURN";
                case Type::T_SUPER:                     return "SUPER";
                case Type::T_THIS:                      return "THIS";
                case Type::T_TRUE:                      return "TRUE";
                case Type::T_WHILE:                     return "WHILE";
                case Type::T_TYPE_VAR:                  return "TYPE_VAR";
                case Type::T_TYPE_STRING:               return "TYPE_STRING";
                case Type::T_TYPE_BOOL:                 return "TYPE_BOOL";
                case Type::T_TYPE_CHAR:                 return "TYPE_CHAR";
                case Type::T_TYPE_U8:                   return "TYPE_U8";
                case Type::T_TYPE_U16:                  return "TYPE_U16";
                case Type::T_TYPE_U32:                  return "TYPE_U32";
                case Type::T_TYPE_U64:                  return "TYPE_U64";
                case Type::T_TYPE_I8:                   return "TYPE_I8";
                case Type::T_TYPE_I16:                  return "TYPE_I16";
                case Type::T_TYPE_I32:                  return "TYPE_I32";
                case Type::T_TYPE_I64:                  return "TYPE_I64";
                case Type::T_TYPE_F32:                  return "TYPE_F32";
                case Type::T_TYPE_F64:                  return "TYPE_F64";
                case Type::T_TYPE_VOID:                 return "TYPE_VOID";
                case Type::T_EOF:                       return "EOF";
                default:                                return "UNKNOWN";
            }
        }

        Token::Type Token::getType() const { return type; }
        string Token::getLexeme() const { return lexeme; }
        types::var_t Token::get() const { return literal; }
        int Token::getLine() const { return line; }
} // namespace dih