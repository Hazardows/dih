// this is just a placeholder header

#pragma once

#include <functional>
#include <string>

namespace dih {
    typedef int64_t var_t;

    bool isNumber(var_t);
    void exeption(std::string message);

    enum class returnType {
        String, Int, Void, Var
    };

    class dihManager {

        public:
        void inject(const std::function<bool(var_t)>&, std::string);
        bool error();
        returnType returnType();
        std::string returned();
    };

    class dihVM {

        public:
        dihVM(dihManager);
        void init();
        bool ready();
        void load(std::string);
        void run();
        void kill();
    };
}