#pragma once

#include <string>

#include "core/platform.h"

namespace dih {
    class DIH_API dihManager {
        public:
        bool had_error = false;
        bool had_runtime_error = false;
    };
    
    DIH_API void run_file(std::string path, dih::dihManager& manager);
    DIH_API void run_code(std::string code, dih::dihManager& manager);
    DIH_API void run_prompt(dih::dihManager& manager);
}