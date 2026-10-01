#pragma once

#include <vector>
#include <memory>

#include "../token/token.hpp"
#include "../ast/expr.hpp"
#include "../ast/stmt.hpp"
#include "../logger/logger.hpp"

namespace dih::parser {

    class Parser {
        public:
        Parser(const std::vector<Token>& tokens, dihManager& manager) 
            : tokens(tokens), current(0), manager(manager) {}
        
            std::vector<std::unique_ptr<stmt::Stmt>> parse() {
            std::vector<std::unique_ptr<stmt::Stmt>> statements;
            try {
                while (!isAtEnd()) {
                    statements.push_back(declaration());
                }
                return statements;
            }
            catch (const Parser::ParseError& error) {
                return {};
            }
        }

        private:
        const std::vector<Token>& tokens;
        size_t current;
        dihManager& manager;

        std::unique_ptr<stmt::Stmt> statement() {
            if (match({Token::Type::T_LEFT_BRACE})) {
                return std::make_unique<stmt::Block>(block());
            }
            else if (match({Token::Type::T_RETURN})) {
                return returnStatement();
            }
            else if (match({Token::Type::T_WHILE})) {
                return whileStatement();
            }
            else if (match({Token::Type::T_FOR})) {
                return forStatement();
            }
            else if (match({Token::Type::T_IF})) {
                return ifStatement();
            }

            return expressionStatement();
        }

        std::unique_ptr <stmt::Stmt> ifStatement() {
            consume(Token::Type::T_LEFT_PARENT, "Expect '(' after 'if'.");
            std::unique_ptr<expr::Expr> condition = expression();
            consume(Token::Type::T_RIGHT_PARENT, "Expect ')' after if condition.");

            std::unique_ptr<stmt::Stmt> thenBranch = statement();
            std::unique_ptr<stmt::Stmt> elseBranch = nullptr;
            if (match({Token::Type::T_ELSE})) {
                elseBranch = statement();
            }

            return std::make_unique<stmt::If>(
                std::move(condition),
                std::move(thenBranch),
                std::move(elseBranch)
            );
        }

        std::unique_ptr<stmt::Stmt> expressionStatement() {
            auto value = expression();
            consume(Token::Type::T_SEMICOLON, "Expect ';' after expression.");
            return std::make_unique<stmt::Expression>(std::move(value));
        }

        std::vector<std::unique_ptr<stmt::Stmt>> block() {
            std::vector<std::unique_ptr<stmt::Stmt>> statements = {};

            while (!check(Token::Type::T_RIGHT_BRACE) && !isAtEnd()) {
                statements.push_back(declaration());
            }

            consume(Token::Type::T_RIGHT_BRACE, "Expect '}' after block.");
            return statements;
        }

        std::unique_ptr<stmt::Stmt> functionDeclaration(types::string_t kind) {
            Token name = consume(Token::Type::T_IDENTIFIER, "Expect " + kind + "name.");
            consume(Token::Type::T_LEFT_PARENT, "Expect '(' after" + kind + "name.");
            std::vector<Token> params = {};

            if (!check(Token::Type::T_RIGHT_PARENT)) {
                do {
                    if (params.size() >= 255) {
                        error(peek(), "Can't have more than 255 parameters.");
                    }

                    params.push_back(consume(Token::Type::T_IDENTIFIER, "Expect parameter name."));
                } while (match({Token::Type::T_COMMA}));
            }

            consume(Token::Type::T_RIGHT_PARENT, "Expect ')' after parameters");
            consume(Token::Type::T_LEFT_BRACE, "Expect '{' before " + kind + " body.");

            auto body = block();
            return std::make_unique<stmt::Function>(name, params, std::move(body));
        }

        std::unique_ptr<stmt::Stmt> get_var_dec() {
            if (match({Token::Type::T_TYPE_U8})) {
                return variableDeclaration(dihTypeId::u8_t);
            }
            else if (match({Token::Type::T_TYPE_U16})) {
                return variableDeclaration(dihTypeId::u16_t);
            }
            else if (match({Token::Type::T_TYPE_U32})) {
                return variableDeclaration(dihTypeId::u32_t);
            }
            else if (match({Token::Type::T_TYPE_U64})) {
                return variableDeclaration(dihTypeId::u64_t);
            }
            else if (match({Token::Type::T_TYPE_I8})) {
                return variableDeclaration(dihTypeId::i8_t);
            }
            else if (match({Token::Type::T_TYPE_I16})) {
                return variableDeclaration(dihTypeId::i16_t);
            }
            else if (match({Token::Type::T_TYPE_I32})) {
                return variableDeclaration(dihTypeId::i32_t);
            }
            else if (match({Token::Type::T_TYPE_I64})) {
                return variableDeclaration(dihTypeId::i64_t);
            }
            else if (match({Token::Type::T_TYPE_F32})) {
                return variableDeclaration(dihTypeId::f32_t);
            }
            else if (match({Token::Type::T_TYPE_F64})) {
                return variableDeclaration(dihTypeId::f64_t);
            }
            else if (match({Token::Type::T_TYPE_STRING})) {
                return variableDeclaration(dihTypeId::string_t);
            }
            else if (match({Token::Type::T_TYPE_CHAR})) {
                return variableDeclaration(dihTypeId::char_t);
            }
            else if (match({Token::Type::T_TYPE_BOOL})) {
                return variableDeclaration(dihTypeId::bool_t);
            }
            else if (match({Token::Type::T_TYPE_VAR})) {
                return variableDeclaration(dihTypeId::var_t);
            }
            return nullptr;
        }
        std::unique_ptr<stmt::Stmt> declaration() {
            try {
                std::unique_ptr<stmt::Stmt> vardec = get_var_dec();
                if (vardec != nullptr) {
                    return vardec;
                }
                if (match({Token::Type::T_FUNC})) {
                    return functionDeclaration("function");
                }
                // TODO: Check other types
                return statement();
            }
            catch (const ParseError& error) {
                synchronize();
                return nullptr;
            }
        }

        std::unique_ptr<stmt::Stmt> variableDeclaration(dihTypeId type) {
            std::vector<std::unique_ptr<stmt::Var>> variables;
    
            // Primera variable
            Token name = consume(Token::Type::T_IDENTIFIER, "Expect variable name.");
    
            std::unique_ptr<expr::Expr> initializer = nullptr;
            if (match({Token::Type::T_EQUAL})) {
                initializer = expression();
            }
            variables.push_back(std::make_unique<stmt::Var>(name, std::move(initializer)));
    
            // Variables adicionales
            while (match({Token::Type::T_COMMA})) {
                Token nextName = consume(Token::Type::T_IDENTIFIER, "Expect variable name after ','.");
        
                std::unique_ptr<expr::Expr> nextInitializer = nullptr;
                if (match({Token::Type::T_EQUAL})) {
                    nextInitializer = expression();
                }
                variables.push_back(std::make_unique<stmt::Var>(nextName, std::move(nextInitializer)));
            }
    
            consume(Token::Type::T_SEMICOLON, "Expect ';' after variable declaration.");
            
            // Si solo una variable, devolver Var directamente
            if ((type == dihTypeId::var_t) && (variables.size() == 1)) {
                return std::move(variables[0]);
            }
    
            // Múltiples variables: devolver VarList
            return std::make_unique<stmt::VarList>(std::move(variables), type);
        }

        std::unique_ptr<stmt::Stmt> returnStatement() {
            Token keyword = previous();
            std::unique_ptr<expr::Expr> value = nullptr;
            
            if (!check(Token::Type::T_SEMICOLON)) {
                value = expression();
            }
            else {
                // return; -> return nil;
                value = std::make_unique<expr::Literal>(special::nil);
            }

            consume(Token::Type::T_SEMICOLON, "Expect ';' after return statement.");
            return std::make_unique<stmt::Return>(keyword, std::move(value));
        }

        std::unique_ptr<stmt::Stmt> whileStatement() {
            consume(Token::Type::T_LEFT_PARENT, "Expect '(' after 'while'.");
            auto condition = expression();
            consume(Token::Type::T_RIGHT_PARENT, "Expect ')' after condition.");
            auto body = statement();

            return make_unique<stmt::While>(std::move(condition), std::move(body));
        }

        std::unique_ptr<stmt::Stmt> forStatement() {
            consume(Token::Type::T_LEFT_PARENT, "Expect '(' after 'for'.");

            // Initializer
            std::unique_ptr<stmt::Stmt> initializer;
            if (match({Token::Type::T_SEMICOLON})) {
                initializer = nullptr;
            }
            else {
                std::unique_ptr<stmt::Stmt> vardec = get_var_dec();
                if (vardec != nullptr) {
                    initializer = std::move(vardec);
                }
                else {
                    initializer = expressionStatement();
                }
            }
            
            // Condition
            std::unique_ptr<expr::Expr> condition = nullptr;
            if (!check(Token::Type::T_SEMICOLON)) {
                condition = expression();
            }
            consume(Token::Type::T_SEMICOLON, "Expect ';' after loop condition.");
            
            // Increment
            std::unique_ptr<expr::Expr> increment = nullptr;
            if (!check(Token::Type::T_RIGHT_PARENT)) {
                increment = expression();
            }
            consume(Token::Type::T_RIGHT_PARENT, "Expect ')' after for clauses.");

            // Body
            auto body = statement();
            
            // Turn into while loop
            // for (init; condition; increment)
            // -> {init; while(condiiton) { body; increment; }}
            std::vector<std::unique_ptr<stmt::Stmt>> statements;

            // Initializer
            if (initializer != nullptr) {
                statements.push_back(std::move(initializer));
            }

            // Build while loop
            // Body
            std::vector<std::unique_ptr<stmt::Stmt>> whileBody;
            whileBody.push_back(std::move(body));
            
            // Increment
            if (increment != nullptr) {
                whileBody.push_back(std::make_unique<stmt::Expression>(std::move(increment)));
            }

            // Condition
            if (condition == nullptr) {
                condition = std::make_unique<expr::Literal>(true);
            }

            // Create the while loop
            auto whileLoop = std::make_unique<stmt::While>(
                std::move(condition),
                std::make_unique<stmt::Block>(std::move(whileBody))
            );
            statements.push_back(std::move(whileLoop));

            return std::make_unique<stmt::Block>(std::move(statements));
        }

        // syntactic analysis
        std::unique_ptr<expr::Expr> expression() {
            return assignment();
        }

        Token createBinaryOpFromCompound(const Token& compound) {
            switch (compound.getType()) {
                case Token::Type::T_PLUS_EQUAL:
                    return Token(Token::Type::T_PLUS, "+", compound.getLine());
                case Token::Type::T_MINUS_EQUAL:
                    return Token(Token::Type::T_MINUS, "-", compound.getLine());
                case Token::Type::T_ASTERISK_EQUAL:
                    return Token(Token::Type::T_ASTERISK, "*", compound.getLine());
                case Token::Type::T_ASTERISK_ASTERISK_EQUAL:
                    return Token(Token::Type::T_ASTERISK_ASTERISK, "**", compound.getLine());
                case Token::Type::T_SLASH_EQUAL:
                    return Token(Token::Type::T_SLASH, "/", compound.getLine());
                default:
                    throw error(compound, "Unknown compound assignment operator.");
            }
        }

        std::unique_ptr<expr::Expr> assignment() {
            auto expr = orExpr();

            if (match({
                Token::Type::T_EQUAL,
                Token::Type::T_PLUS_EQUAL,
                Token::Type::T_MINUS_EQUAL,
                Token::Type::T_ASTERISK_EQUAL,
                Token::Type::T_ASTERISK_ASTERISK_EQUAL,
                Token::Type::T_SLASH_EQUAL,
                })) {
                Token equals = previous();
                auto value = assignment();

                // Try downcast to variable
                if (auto* varExpr = dynamic_cast<expr::Variable*>(expr.get())) {
                    Token name = varExpr->name;

                    if (equals.getType() == Token::Type::T_EQUAL) {
                        return std::make_unique<expr::Assign>(name, std::move(value));
                    }

                    // compund assign
                    Token op = createBinaryOpFromCompound(equals);
                    auto binaryOp = std::make_unique<expr::Binary>(
                        std::make_unique<expr::Variable>(name),
                        op,
                        std::move(value)  
                    );

                    return std::make_unique<expr::Assign>(name, std::move(binaryOp));
                }
            
                logger::error(equals, "Invalid assignment target.", manager);
            }

            return expr;
        }

        std::unique_ptr<expr::Expr> orExpr() {
            auto expr = andExpr();

            while (match({Token::Type::T_OR})) {
                Token op = previous();
                auto right = andExpr();
                expr = make_unique<expr::Logical>(std::move(expr), op, std::move(right));
            }

            return expr;
        }

        std::unique_ptr<expr::Expr> andExpr() {
            auto expr = equality();

            while (match({Token::Type::T_AND})) {
                Token op = previous();
                auto right = equality();
                expr = make_unique<expr::Logical>(std::move(expr), op, std::move(right));
            }

            return expr;
        }

        std::unique_ptr<expr::Expr> equality() {
            auto expr = comparison();
            while (match({Token::Type::T_BANG_EQUAL, Token::Type::T_EQUAL_EQUAL})) {
                Token op = previous();
                auto right = comparison();
                expr = std::make_unique<expr::Binary>(std::move(expr), op, std::move(right));
            }
            return expr;
        }
        
        std::unique_ptr<expr::Expr> comparison() {
            auto expr = term();
            while (match({Token::Type::T_GREATER, Token::Type::T_GREATER_EQUAL,
                          Token::Type::T_LESS, Token::Type::T_LESS_EQUAL})) {
                Token op = previous();
                auto right = term();
                expr = std::make_unique<expr::Binary>(std::move(expr), op, std::move(right));
            }
            return expr;
        }
        
        std::unique_ptr<expr::Expr> term() {
            auto expr = factor();
            while (match({Token::Type::T_MINUS, Token::Type::T_PLUS})) {
                Token op = previous();
                auto right = factor();
                expr = std::make_unique<expr::Binary>(std::move(expr), op, std::move(right));
            }
            return expr;
        }
        
        std::unique_ptr<expr::Expr> factor() {
            auto expr = exponentiation();
            while (match({Token::Type::T_SLASH, Token::Type::T_ASTERISK})) {
                Token op = previous();
                auto right = exponentiation();
                expr = std::make_unique<expr::Binary>(std::move(expr), op, std::move(right));
            }
            return expr;
        }
        
        std::unique_ptr<expr::Expr> exponentiation() {
            auto expr = unary();
            if (match({Token::Type::T_ASTERISK_ASTERISK})) {
                Token op = previous();
                auto right = exponentiation();
                expr = std::make_unique<expr::Binary>(std::move(expr), op, std::move(right));
            }
            return expr;
        }
        
        std::unique_ptr<expr::Expr> unary() {
            if (match({Token::Type::T_BANG, Token::Type::T_MINUS})) {
                Token op = previous();
                auto right = unary();
                return std::make_unique<expr::Unary>(op, std::move(right));
            }
            return call();
        }

        std::unique_ptr<expr::Expr> finishCall(std::unique_ptr<expr::Expr> callee) {
            std::vector<std::unique_ptr<expr::Expr>> arguments;
    
            if (!check(Token::Type::T_RIGHT_PARENT)) {
                do {
                    if (arguments.size() >= 255) {  // Límite de argumentos
                        error(peek(), "Can't have more than 255 arguments.");
                    }
                    arguments.push_back(expression());
                } while (match({Token::Type::T_COMMA}));
            }
    
            Token paren = consume(Token::Type::T_RIGHT_PARENT, "Expect ')' after arguments.");
            return std::make_unique<expr::Call>(std::move(callee), paren, std::move(arguments));
        }

        std::unique_ptr<expr::Expr> call() {
            auto expr = increment();
    
            while (true) {
                if (match({Token::Type::T_LEFT_PARENT})) {
                    expr = finishCall(std::move(expr));
                }
                else {
                    break;
                }
            }
    
            return expr;
        }

        std::unique_ptr<expr::Expr> increment() {
            // prefix: ++x
            if (match({Token::Type::T_PLUS_PLUS})) {
                Token op = previous();
                auto expr = primary();
        
                // Verify it's a variable
                if (auto* varExpr = dynamic_cast<expr::Variable*>(expr.get())) {
                    return std::make_unique<expr::Increment>(op, varExpr->name, true);
                }
                logger::error(op, "Invalid operand for increment. Must be a variable.", manager);
            }
    
            if (match({Token::Type::T_MINUS_MINUS})) {
                Token op = previous();
                auto expr = primary();
        
                if (auto* varExpr = dynamic_cast<expr::Variable*>(expr.get())) {
                    return std::make_unique<expr::Increment>(op, varExpr->name, true);
                }
                logger::error(op, "Invalid operand for decrement. Must be a variable.", manager);
            }
    
            auto expr = primary();
    
            // sufix: x++
            if (match({Token::Type::T_PLUS_PLUS})) {
                Token op = previous();
                if (auto* varExpr = dynamic_cast<expr::Variable*>(expr.get())) {
                    return std::make_unique<expr::Increment>(op, varExpr->name, false);
                }
                logger::error(op, "Invalid operand for increment. Must be a variable.", manager);
            }
    
            if (match({Token::Type::T_MINUS_MINUS})) {
                Token op = previous();
                if (auto* varExpr = dynamic_cast<expr::Variable*>(expr.get())) {
                    return std::make_unique<expr::Increment>(op, varExpr->name, false);
                }
                logger::error(op, "Invalid operand for decrement. Must be a variable.", manager);
            }
    
            return expr;
        }
        
        std::unique_ptr<expr::Expr> primary() {
            if (match({Token::Type::T_FALSE})) {
                return std::make_unique<expr::Literal>(false);
            }
            else if (match({Token::Type::T_TRUE})) {
                return std::make_unique<expr::Literal>(true);
            }
            else if (match({Token::Type::T_NIL})) {
                return std::make_unique<expr::Literal>(special::nil);
            }
            else if (match({Token::Type::T_NUMBER, Token::Type::T_STRING})) {
                Token token = previous();
                return std::make_unique<expr::Literal>(token.get());
            }
            else if (match({Token::Type::T_LEFT_PARENT})) {
                auto expr = expression();
                consume(Token::Type::T_RIGHT_PARENT, "Expect ')' after expression.");
                return std::make_unique<expr::Grouping>(std::move(expr));
            }
            else if (match({Token::Type::T_IDENTIFIER})) {
                return std::make_unique<expr::Variable>(previous());
            }

            throw error(peek(), "Expect expression.");
        }

        // error management
        class ParseError : public std::runtime_error {
            public:
            ParseError() : runtime_error("Parse error") {}
        };

        ParseError error(const Token& token, const std::string& message) {
            logger::error(token, message, manager);
            return ParseError();
        }

        void synchronize() {
            advance();
            while (!isAtEnd()) {
                if (previous().getType() == Token::Type::T_SEMICOLON) return;
                switch (peek().getType()) {
                    case Token::Type::T_CLASS:
                    case Token::Type::T_FUNC:
                    case Token::Type::T_TYPE_VAR:
                    case Token::Type::T_FOR:
                    case Token::Type::T_IF:
                    case Token::Type::T_WHILE:
                    case Token::Type::T_RETURN:
                        return;
                    default:
                        break;
                }
                advance();
            }
        }

        // helper methods
        bool match(const std::vector<Token::Type>& types) {
            for (Token::Type type : types) {
                if (check(type)) {
                    advance();
                    return true;
                }
            }
            return false;
        }

        bool check(Token::Type type) const {
            if (isAtEnd()) return false;
            return peek().getType() == type;
        }
        
        Token advance() {
            if (!isAtEnd()) ++current;
            return previous();
        }
        
        bool isAtEnd() const {
            return peek().getType() == Token::Type::T_EOF;
        }
        
        Token peek() const {
            return tokens[current];
        }
        
        Token previous() const {
            return tokens[current - 1];
        }
        
        Token consume(Token::Type type, const std::string& message) {
            if (check(type)) return advance();
            throw error(peek(), message);
        }
    };
} // namespace dih::parser