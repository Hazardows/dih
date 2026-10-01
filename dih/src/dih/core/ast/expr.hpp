#pragma once

#include <memory>
#include <string>
#include <vector>

#include "../token/token.hpp"
#include "../types.hpp"

namespace dih::expr {

    class Assign;
    class Binary;
    class Call;
    class Grouping;
    class Increment;
    class Literal;
    class Logical;
    class Unary;
    class Variable;

    class Visitor {

        public:
        virtual ~Visitor() = default;
        virtual dih::special::dihValueContainer visitAssign(const Assign& node) = 0;
        virtual dih::special::dihValueContainer visitBinary(const Binary& node) = 0;
        virtual dih::special::dihValueContainer visitCall(const Call& node) = 0;
        virtual dih::special::dihValueContainer visitGrouping(const Grouping& node) = 0;
        virtual dih::special::dihValueContainer visitIncrement(const Increment& node) = 0;
        virtual dih::special::dihValueContainer visitLiteral(const Literal& node) = 0;
        virtual dih::special::dihValueContainer visitLogical(const Logical& node) = 0;
        virtual dih::special::dihValueContainer visitUnary(const Unary& node) = 0;
        virtual dih::special::dihValueContainer visitVariable(const Variable& node) = 0;
    };

    class Expr {

        public:
        virtual ~Expr() = default;

        virtual dih::special::dihValueContainer accept(Visitor& visitor) const = 0;
    };

    class Assign : public Expr {

        public:
        Assign(Token name, std::unique_ptr<expr::Expr> value)
        : name(name), value(std::move(value)) {}

        dih::special::dihValueContainer accept(Visitor& visitor) const override {
            return visitor.visitAssign(*this);
        }

        // Fields
        Token name;
        std::unique_ptr<expr::Expr> value;
    };

    class Binary : public Expr {

        public:
        Binary(std::unique_ptr<expr::Expr> left, Token op, std::unique_ptr<expr::Expr> right)
        : left(std::move(left)), op(op), right(std::move(right)) {}

        dih::special::dihValueContainer accept(Visitor& visitor) const override {
            return visitor.visitBinary(*this);
        }

        // Fields
        std::unique_ptr<expr::Expr> left;
        Token op;
        std::unique_ptr<expr::Expr> right;
    };

    class Call : public Expr {

        public:
        Call(std::unique_ptr<expr::Expr> callee, Token paren, std::vector<std::unique_ptr<expr::Expr>> arguments)
        : callee(std::move(callee)), paren(paren), arguments(std::move(arguments)) {}

        dih::special::dihValueContainer accept(Visitor& visitor) const override {
            return visitor.visitCall(*this);
        }

        // Fields
        std::unique_ptr<expr::Expr> callee;
        Token paren;
        std::vector<std::unique_ptr<expr::Expr>> arguments;
    };

    class Grouping : public Expr {

        public:
        Grouping(std::unique_ptr<expr::Expr> expression)
        : expression(std::move(expression)) {}

        dih::special::dihValueContainer accept(Visitor& visitor) const override {
            return visitor.visitGrouping(*this);
        }

        // Fields
        std::unique_ptr<expr::Expr> expression;
    };

    class Increment : public Expr {

        public:
        Increment(Token op, Token name, bool isPrefix)
        : op(op), name(name), isPrefix(isPrefix) {}

        dih::special::dihValueContainer accept(Visitor& visitor) const override {
            return visitor.visitIncrement(*this);
        }

        // Fields
        Token op;
        Token name;
        bool isPrefix;
    };

    class Literal : public Expr {

        public:
        Literal(types::var_t value)
        : value(value) {}

        dih::special::dihValueContainer accept(Visitor& visitor) const override {
            return visitor.visitLiteral(*this);
        }

        // Fields
        types::var_t value;
    };

    class Logical : public Expr {

        public:
        Logical(std::unique_ptr<expr::Expr> left, Token op, std::unique_ptr<expr::Expr> right)
        : left(std::move(left)), op(op), right(std::move(right)) {}

        dih::special::dihValueContainer accept(Visitor& visitor) const override {
            return visitor.visitLogical(*this);
        }

        // Fields
        std::unique_ptr<expr::Expr> left;
        Token op;
        std::unique_ptr<expr::Expr> right;
    };

    class Unary : public Expr {

        public:
        Unary(Token op, std::unique_ptr<expr::Expr> right)
        : op(op), right(std::move(right)) {}

        dih::special::dihValueContainer accept(Visitor& visitor) const override {
            return visitor.visitUnary(*this);
        }

        // Fields
        Token op;
        std::unique_ptr<expr::Expr> right;
    };

    class Variable : public Expr {

        public:
        Variable(Token name)
        : name(name) {}

        dih::special::dihValueContainer accept(Visitor& visitor) const override {
            return visitor.visitVariable(*this);
        }

        // Fields
        Token name;
    };

} // namespace dih::expr
