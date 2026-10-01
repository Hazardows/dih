#pragma once

#include <string>

#include "../platform.h"
#include "expr.hpp"

namespace dih {

    class AstPrinter : public expr::Visitor {
    
        public:
        std::string print(const expr::Expr& expr) {
            return toString(expr.accept(*this));
        }
    
        private:
        special::dihValueContainer visitBinary(const expr::Binary& expr) override {
            return special::dihValueContainer(parenthesize(expr.op.getLexeme(), *expr.left, *expr.right));
        }
    
        special::dihValueContainer visitGrouping(const expr::Grouping& expr) override {
            return special::dihValueContainer(parenthesize("group", *expr.expression));
        }
    
        special::dihValueContainer visitLiteral(const expr::Literal& expr) override {
            return expr.value;
        }
    
        special::dihValueContainer visitUnary(const expr::Unary& expr) override {
            return special::dihValueContainer(parenthesize(expr.op.getLexeme(), *expr.right));
        }

        std::string parenthesize(const std::string& name, const expr::Expr& expr) {
            return "(" + name + " " + toString(expr.accept(*this)) + ")";
        }
        
        std::string parenthesize(const std::string& name, const expr::Expr& left, const expr::Expr& right) {
            return "(" + name + " " + toString(left.accept(*this)) + " " + toString(right.accept(*this)) + ")";
        }
    };
} // namespace dih