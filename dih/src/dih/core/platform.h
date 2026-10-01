#pragma once

// Windows
#if defined(_WIN32) || defined(__CYGWIN__)
    #ifdef DIH_API_EXPORT
        #define DIH_API __declspec(dllexport)
    #else
        #define DIH_API __declspec(dllimport)
    #endif
#else   // Linux, macOS, other Unix systems
    #ifdef DIH_API_EXPORT
        #define DIH_API __attribute__((visibility("default")))
    #else
        #define DIH_API
    #endif
#endif