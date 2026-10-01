#include "callable.hpp"
#include "interpreter.hpp"

namespace dih {
    // NativeFunction
    NativeFunction::NativeFunction(const std::string& name,
        std::function<special::dihValueContainer(dihi&, const std::vector<special::dihValueContainer>&)> function,
        types::i16_t arity)
        : name(name), function(function), arity_value(arity) {}

    types::i16_t NativeFunction::arity() const { return arity_value; }
        
    special::dihValueContainer NativeFunction::call(dihi& interpreter, const std::vector<special::dihValueContainer>& arguments) {
        return function(interpreter, arguments);
    }
        
    std::string NativeFunction::toString() const {
        return "<native function " + name + ">";
    }

    types::string_t NativeFunction::getName() const {
        return name;
    }

    // DihFunction
    DihFunction::DihFunction(const stmt::Function* declaration, std::shared_ptr<interpreter::Environment> closure) 
        : declaration(declaration), closure(closure) {
        if (!this->closure) {
            this->closure = std::make_shared<interpreter::Environment>();
        }
    }

    types::i16_t DihFunction::arity() const {
        return (types::i16_t)declaration->params.size();
    }

    special::dihValueContainer DihFunction::call(dihi& interpreter, const std::vector<special::dihValueContainer>& arguments) {
        auto env = std::make_shared<interpreter::Environment>();
        env->setEnclosing(closure);
    
        for (types::i16_t i = 0; i < (types::i16_t)declaration->params.size(); i++) {
            // todo: change this to allow use of non-var data types
            env->define(declaration->params[i], arguments[i], dihTypeId::var_t);
        }

        auto previous = interpreter.environment;
        interpreter.environment = env;
    
        try {
            interpreter.executeBlock(declaration->body, env);
        }
        catch (const Return& ret) {
            interpreter.environment = previous;
            return ret.value;
        }
    
        interpreter.environment = previous;
        return special::dihValueContainer(special::nil);
    }

    std::string DihFunction::toString() const {
        return "<function " + declaration->name.getLexeme() + ">";
    }

    types::string_t DihFunction::getName() const {
        return declaration->name.getLexeme();
    }
}