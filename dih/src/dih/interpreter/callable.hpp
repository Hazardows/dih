#pragma once

#include <string>
#include <vector>
#include <memory>
#include <functional>

#include "../core/types.hpp"
#include "../core/ast/stmt.hpp"
#include "environment.hpp"

namespace dih {
    class dihi;

    class Callable {
        
        public:
        virtual ~Callable() = default;
        virtual types::i16_t arity() const = 0;
        virtual special::dihValueContainer call(dihi& interpreter, const std::vector<special::dihValueContainer>& arguments) = 0;
        virtual types::string_t toString() const = 0;
        virtual types::string_t getName() const = 0;
    };
    
    class NativeFunction : public Callable {
    
        private:
        types::string_t name;
        std::function<special::dihValueContainer(dihi&, const std::vector<special::dihValueContainer>&)> function;
        types::i16_t arity_value;

        public:
        NativeFunction(const std::string& name,
                      std::function<special::dihValueContainer(dihi&, const std::vector<special::dihValueContainer>&)> function,
                      types::i16_t arity = 0);
        types::i16_t arity() const override;
        special::dihValueContainer call(dihi& interpreter, const std::vector<special::dihValueContainer>& arguments) override;
        types::string_t toString() const override;
        types::string_t getName() const override;
    };

    class DihFunction : public Callable {
        
        private:
        const stmt::Function* declaration;
        std::shared_ptr<interpreter::Environment> closure;

        public:
        class Return : public std::exception {

            public:
            special::dihValueContainer value;
            Return(special::dihValueContainer value) : value(value) {}
        };

        DihFunction(const stmt::Function* declaration, std::shared_ptr<interpreter::Environment> closure);
        types::i16_t arity() const override;
        special::dihValueContainer call(dihi& interpreter, const std::vector<special::dihValueContainer>& arguments) override;
        types::string_t toString() const override;
        types::string_t getName() const override;
    };
} // dih