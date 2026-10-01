#pragma once

#include <cmath>
#include <string>
#include <iostream>

#include "../core/ast/expr.hpp"
#include "../core/ast/stmt.hpp"
#include "../core/token/token.hpp"
#include "../core/platform.h"
#include "../core/types.hpp"
#include "../core/logger/logger.hpp"

#include "environment.hpp"
#include "callable.hpp"
#include "interactor.hpp"

namespace dih {

    // Interpreter for dih code
    class dihi : public expr::Visitor, public stmt::Visitor {

        public:
        std::shared_ptr<interpreter::Environment> globals = {};
        std::shared_ptr<interpreter::Environment> environment;
        
        void inject(std::shared_ptr<NativeFunction> func) {
            Token funcToken(Token::Type::T_IDENTIFIER, func->getName(), 0);
            try {
                globals->define(funcToken, std::static_pointer_cast<Callable>(func), dihTypeId::internal_callable);
            }
            catch (logger::types::RuntimeError& rte) {
                throw logger::types::RuntimeError("Failed to insert function, " + std::string(rte.what()));
            }
        }

        dihi() : globals(std::make_shared<interpreter::Environment>()), environment(globals) {
            // Native functions
            auto print = std::make_shared<NativeFunction>(
                "print",
                [](dihi& interpreter, const std::vector<special::dihValueContainer>& args) -> special::dihValueContainer {
                    (void)interpreter;
                    for (const special::dihValueContainer& i : args) {
                        std::cout << i.stingize();
                    }
                    return special::dihValueContainer(special::nil);
                },
                -1
            );
            this->inject(print);

            auto println = std::make_shared<NativeFunction>(
                "println",
                [](dihi& interpreter, const std::vector<special::dihValueContainer>& args) -> special::dihValueContainer {
                    (void)interpreter;
                    for (const special::dihValueContainer& i : args) {
                        std::cout << i.stingize();
                    }
                    std::cout << std::endl;
                    return special::dihValueContainer(special::nil);
                },
                -1
            );
            this->inject(println);

            auto input = std::make_shared<NativeFunction>(
                "input",
                [](dihi& interpreter, const std::vector<special::dihValueContainer>& args) -> special::dihValueContainer {
                    (void)interpreter;
                    (void)args;

                    std::string token;
                    std::cin >> token;
        
                    // Try i64
                    char* endptr;
                    types::i64_t int_val = strtoll(token.c_str(), &endptr, 10);
                    if (*endptr == '\0') {
                        return special::dihValueContainer((types::i64_t)int_val);
                    }
        
                    // Try f64
                    types::f64_t double_val = strtod(token.c_str(), &endptr);
                    if (*endptr == '\0') {
                        return special::dihValueContainer(double_val);
                    }
        
                    // Try bool
                    if (token == "true" || token == "True" || token == "TRUE") {
                        return special::dihValueContainer((types::bool_t)true);
                    }
                    else if (token == "false" || token == "False" || token == "FALSE") {
                        return special::dihValueContainer((types::bool_t)false);
                    }
                    
                    // Try char
                    if (token.length() == 1) {
                        return special::dihValueContainer((types::char_t)token[0]);
                    }
        
                    // Default: string
                    return special::dihValueContainer((types::string_t)token);
                },
                0
            );
            this->inject(input);
        }

        void interpret(const std::vector<std::unique_ptr<stmt::Stmt>>& statements, dihManager& manager) {
            try {
                for (const auto& statement : statements) {
                    execute(*statement);
                }
            }
            catch (logger::types::RuntimeError& error) {
                logger::runtimeError(error, manager);
            }
            catch (const std::exception& e) {
                std::cerr << "Internal error: " << e.what() << std::endl;
            }
        }

        void executeBlock(const std::vector<std::unique_ptr<stmt::Stmt>>& statements, std::shared_ptr<interpreter::Environment> env, bool is_super = false) {
            auto previous = this->environment;
            this->environment = env;
            for (const auto& statement : statements) {
                execute(*statement);
            }
            this->environment = previous;
        }
        
        private:
        special::dihValueContainer evaluate(const expr::Expr& e) {
            return e.accept(*this);
        }

        void execute(const stmt::Stmt& stmt) {
            stmt.accept(*this);
        }

        // helper functions
        types::bool_t isTruthy(special::dihValueContainer e) const {
            e = interactor::unwrap_var(e);
            switch (e.type_id) {
                case dihTypeId::u8_t: return e.get_u8() > 0;
                case dihTypeId::u16_t: return e.get_u16() > 0;
                case dihTypeId::u32_t: return e.get_u32() > 0;
                case dihTypeId::u64_t: return e.get_u64() > 0;
                case dihTypeId::i8_t: return e.get_i8() > 0;
                case dihTypeId::i16_t: return e.get_i16() > 0;
                case dihTypeId::i32_t: return e.get_i32() > 0;
                case dihTypeId::i64_t: return e.get_i64() > 0;
                case dihTypeId::f32_t: return e.get_f32() > 0;
                case dihTypeId::f64_t: return e.get_f64() > 0;
                case dihTypeId::bool_t: return e.get_bool();
                case dihTypeId::internal_ptr: return (types::bool_t)e.get_ptr().alloc->alive;
                case dihTypeId::internal_nil: return false;
                // case dihTypeId::char_t: return true;
                // case dihTypeId::string_t: return true;
                // case dihTypeId::internal_callable: return true;
                // case dihTypeId::var_t: return false;
                default: return true;
            }
            return true;
        }

        void checkNumberOp(Token op, special::dihValueContainer operand) {
            if (interactor::is_numeric(interactor::unwrap_var(operand).type_id)) return;
            throw logger::types::RuntimeError(op, "Operand must be a number.");
        }


        // Visitors (Expr)
        special::dihValueContainer visitLiteral(const expr::Literal& expr) override {
            if (!expr.value.has_value()) {
                return special::dihValueContainer(special::nil);
            }
            return special::dihValueContainer(expr.value);
        }

        special::dihValueContainer visitGrouping(const expr::Grouping& expr) override {
            return evaluate(*expr.expression);
        }

        special::dihValueContainer visitUnary(const expr::Unary& expr) override {
            special::dihValueContainer right = evaluate(*expr.right);
            right = interactor::unwrap_var(right);

            switch (expr.op.getType()) {
                case Token::Type::T_BANG:
                    return special::dihValueContainer(!isTruthy(right));
                case Token::Type::T_MINUS: {
                    checkNumberOp(expr.op, right);
                    return special::dihValueContainer(-toNumber(right));
                }
                default:
                    return special::dihValueContainer((types::var_t)special::nil);
            }
        }

        special::dihValueContainer visitBinary(const expr::Binary& expr) override {
            special::dihValueContainer leftvc = evaluate(*expr.left);
            special::dihValueContainer rightvc = evaluate(*expr.right);

            switch (expr.op.getType()) {
                case Token::Type::T_PLUS: {
                    return interactor::interact_add(leftvc, rightvc);
                }
                case Token::Type::T_MINUS: {                  
                    return interactor::interact_sub(leftvc, rightvc);
                }
                case Token::Type::T_SLASH: {
                    return interactor::interact_div(leftvc, rightvc);
                }
                case Token::Type::T_ASTERISK: {
                    return interactor::interact_mul(leftvc, rightvc);
                }
                case Token::Type::T_ASTERISK_ASTERISK: {
                    return interactor::interact_pow(leftvc, rightvc);
                }
                case Token::Type::T_GREATER: {
                    return interactor::interact_greater(leftvc, rightvc);
                }
                case Token::Type::T_GREATER_EQUAL: {
                    return interactor::interact_greater_equal(leftvc, rightvc);
                }
                case Token::Type::T_LESS: {
                    return interactor::interact_less(leftvc, rightvc);
                }
                case Token::Type::T_LESS_EQUAL: {
                    return interactor::interact_less_equal(leftvc, rightvc);
                }
                case Token::Type::T_BANG_EQUAL: {
                    return interactor::interact_not_equal(leftvc, rightvc);
                }
                case Token::Type::T_EQUAL_EQUAL: {
                    return interactor::interact_equal(leftvc, rightvc);
                }
                default: return special::dihValueContainer((types::var_t)special::nil);
            }
        }

        special::dihValueContainer visitCall(const expr::Call& expr) override {
            auto callee = evaluate(*expr.callee);
            callee = interactor::unwrap_var(callee, true);

            // Check if the function is callable
            if (callee.type_id != dihTypeId::internal_callable) {
                throw logger::types::RuntimeError(expr.paren, "Can only call functions and classes.");
            }

            std::vector<special::dihValueContainer> arguments;
            for (const auto& arg : expr.arguments) {
                arguments.push_back(evaluate(*arg));
            }

            auto function = callee.get_Callable();
            
            // Verify arity
            types::i16_t arity = function->arity();
            if ((arity != -1) && ((types::i16_t)arguments.size() != arity)) {
                throw logger::types::RuntimeError(expr.paren,
                    "Expected " + std::to_string(arity) + " arguments but got " +
                    std::to_string(arguments.size()) + "."
                );
            }
    
            return function->call(*this, arguments);
        }

        special::dihValueContainer visitVariable(const expr::Variable& expr) override {
            return environment->get(expr.name);
        }

        special::dihValueContainer visitAssign(const expr::Assign& expr) override {
            special::dihValueContainer value = evaluate(*expr.value);
            environment->assign(expr.name, value);
            return value;
        }

        special::dihValueContainer visitLogical(const expr::Logical& expr) override {
            special::dihValueContainer left = evaluate(*expr.left);
            left = interactor::unwrap_var(left);
            
            if (expr.op.getType() == Token::Type::T_OR) {
                if (isTruthy(left)) {
                    return left;
                }
            }
            else {
                if (!isTruthy(left)) {
                    return left;
                }
            }

            return evaluate(*expr.right);
        }

        special::dihValueContainer visitIncrement(const expr::Increment& expr) override {
            // Obtain the current value
            special::dihValueContainer current = environment->get(expr.name);
            special::dihValueContainer num = 0;
            if (expr.op.getType() == Token::Type::T_MINUS_MINUS) {
                num = interactor::interact_sub(current, types::i8_t(1));
            }
            else {
                num = interactor::interact_add(current, types::i8_t(1));
            }

            // Assign new value
            environment->assign(expr.name, num);
    
            // Return based on prefix/sufix
            if (expr.isPrefix) {
                return num;
            }
            return current;
        }

        // Visitors (Stmt)
        void visitExpression(const stmt::Expression& stmt) override {
            evaluate(*stmt.expression);
        }

        void visitFunction(const stmt::Function& stmt) override {
            auto function = std::make_shared<DihFunction>(&stmt, environment);
            environment->define(stmt.name, std::static_pointer_cast<Callable>(function), dihTypeId::internal_callable);
        }

        void visitIf(const stmt::If& stmt) override {
            if (isTruthy(evaluate(*stmt.condition))) {
                execute(*stmt.thenBranch);
            }
            else if (stmt.elseBranch != nullptr) {
                execute(*stmt.elseBranch);
            }
        }

        void visitVar(const stmt::Var& stmt) override {
            special::dihValueContainer value(dihTypeId::var_t);
            if (stmt.initializer != nullptr) {
                value = evaluate(*stmt.initializer);
            }

            environment->define(stmt.name, value, dihTypeId::var_t);
        }

        void visitVarList(const stmt::VarList& stmt) override {
            for (const auto& var : stmt.variables) {
                special::dihValueContainer value(stmt.type_id);
                if (var->initializer != nullptr) {
                    value = evaluate(*var->initializer);
                }
                environment->define(var->name, value, stmt.type_id);
            }
        }

        void visitReturn(const stmt::Return& stmt) override {
            throw DihFunction::Return(evaluate(*stmt.value));
        }

        void visitWhile(const stmt::While& stmt) override {
            while (isTruthy(evaluate(*stmt.condition))) {
                execute(*stmt.body);
            }
        }

        void visitBlock(const stmt::Block& stmt) override {
            auto previous = this->environment;
            auto child_env = std::make_shared<interpreter::Environment>();
            child_env->setEnclosing(previous);
            executeBlock(stmt.statements, child_env);
            this->environment = previous;
        }
    };
} // namespace dih