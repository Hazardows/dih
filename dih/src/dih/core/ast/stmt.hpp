#pragma once

#include <memory>
#include <string>
#include <vector>

#include "expr.hpp"
#include "typeid.hpp"
#include "../types.hpp"

namespace dih::stmt {

    class Block;
    class Expression;
    class Return;
    class Function;
    class If;
    class Var;
    class VarList;
    class While;

    class Visitor {

        public:
        virtual ~Visitor() = default;
        virtual void visitBlock(const Block& node) = 0;
        virtual void visitExpression(const Expression& node) = 0;
        virtual void visitReturn(const Return& node) = 0;
        virtual void visitFunction(const Function& node) = 0;
        virtual void visitIf(const If& node) = 0;
        virtual void visitVar(const Var& node) = 0;
        virtual void visitVarList(const VarList& node) = 0;
        virtual void visitWhile(const While& node) = 0;
    };

    class Stmt {

        public:
        virtual ~Stmt() = default;

        virtual void accept(Visitor& visitor) const = 0;
    };

    class Block : public Stmt {

        public:
        Block(std::vector<std::unique_ptr<Stmt>> statements)
        : statements(std::move(statements)) {}

        void accept(Visitor& visitor) const override {
            return visitor.visitBlock(*this);
        }

        // Fields
        std::vector<std::unique_ptr<Stmt>> statements;
    };

    class Expression : public Stmt {

        public:
        Expression(std::unique_ptr<expr::Expr> expression)
        : expression(std::move(expression)) {}

        void accept(Visitor& visitor) const override {
            return visitor.visitExpression(*this);
        }

        // Fields
        std::unique_ptr<expr::Expr> expression;
    };

    class Return : public Stmt {

        public:
        Return(Token keyword, std::unique_ptr<expr::Expr> value)
        : keyword(keyword), value(std::move(value)) {}

        void accept(Visitor& visitor) const override {
            return visitor.visitReturn(*this);
        }

        // Fields
        Token keyword;
        std::unique_ptr<expr::Expr> value;
    };

    class Function : public Stmt {

        public:
        Function(Token name, std::vector<Token> params, std::vector<std::unique_ptr<stmt::Stmt>> body)
        : name(name), params(params), body(std::move(body)) {}

        void accept(Visitor& visitor) const override {
            return visitor.visitFunction(*this);
        }

        // Fields
        Token name;
        std::vector<Token> params;
        std::vector<std::unique_ptr<stmt::Stmt>> body;
    };

    class If : public Stmt {

        public:
        If(std::unique_ptr<expr::Expr> condition, std::unique_ptr<stmt::Stmt> thenBranch, std::unique_ptr<stmt::Stmt> elseBranch)
        : condition(std::move(condition)), thenBranch(std::move(thenBranch)), elseBranch(std::move(elseBranch)) {}

        void accept(Visitor& visitor) const override {
            return visitor.visitIf(*this);
        }

        // Fields
        std::unique_ptr<expr::Expr> condition;
        std::unique_ptr<stmt::Stmt> thenBranch;
        std::unique_ptr<stmt::Stmt> elseBranch;
    };

    class Var : public Stmt {

        public:
        Var(Token name, std::unique_ptr<expr::Expr> initializer)
        : name(name), initializer(std::move(initializer)) {}

        void accept(Visitor& visitor) const override {
            return visitor.visitVar(*this);
        }

        // Fields
        Token name;
        std::unique_ptr<expr::Expr> initializer;
    };

    class VarList : public Stmt {

        public:
        VarList(std::vector<std::unique_ptr<Var>> variables, dihTypeId type_id)
        : variables(std::move(variables)), type_id(type_id) {}

        void accept(Visitor& visitor) const override {
            return visitor.visitVarList(*this);
        }

        // Fields
        std::vector<std::unique_ptr<Var>> variables;
        dihTypeId type_id;
    };

    class While : public Stmt {

        public:
        While(std::unique_ptr<expr::Expr> condition, std::unique_ptr<stmt::Stmt> body)
        : condition(std::move(condition)), body(std::move(body)) {}

        void accept(Visitor& visitor) const override {
            return visitor.visitWhile(*this);
        }

        // Fields
        std::unique_ptr<expr::Expr> condition;
        std::unique_ptr<stmt::Stmt> body;
    };

} // namespace dih::stmt
