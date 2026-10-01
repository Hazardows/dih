#pragma once

#include "../../vendor/ankerl/unordered_dense.h"

#include "../core/types.hpp"
#include "../core/token/token.hpp"
#include "../core/logger/logger.hpp"

#include "interactor.hpp"

namespace dih::interpreter {

    class Environment {
        private:
        ankerl::unordered_dense::map<types::string_t, special::dihValueContainer> values = {};
        std::shared_ptr<Environment> enclosing = nullptr;

        public:
        Environment() : enclosing(nullptr) {}
        Environment(Environment* enclosing)
            : enclosing(enclosing) {}

        void setEnclosing(std::shared_ptr<Environment>& enclosing) {
            this->enclosing = enclosing;
        }

        void define(const Token& name, special::dihValueContainer value, dihTypeId type) {
            // todo: change this to ensure propper type initialization
            // make sure type is assignable to whatever were getting as a value
            // i need to implement assign interactors for this
            
            const types::string_t& str_name = name.getLexeme();
            auto [it, inserted] = values.try_emplace(str_name, interactor::interact_assign(type, value));
            if (!inserted) {
                throw logger::types::RuntimeError(name, "Variable '" + str_name + "' already declared in this scope.");
            }
        }

        special::dihValueContainer get(const Token& name) const {
            const types::string_t& str_name = name.getLexeme();
            auto it = values.find(str_name);
            if (it != values.end()) {
                return it->second;
            }

            if (enclosing != nullptr) {
                return enclosing->get(name);
            }

            throw logger::types::RuntimeError(name, "Undefined variable '" + str_name + "'.");
        }

        void assign(const Token& name, special::dihValueContainer value) {
            const types::string_t& str_name = name.getLexeme();
            auto it = values.find(str_name);
            if (it != values.end()) {
                it->second = interactor::interact_assign(it->second.type_id, value);
                return;
            }

            if (enclosing != nullptr) {
                enclosing->assign(name, value);
                return;
            }

            throw logger::types::RuntimeError(name, "Undefined variable '" + str_name + "'.");
        }
    };

} // namespace dih::interpreter