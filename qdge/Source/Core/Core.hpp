#pragma once

#if defined QDGE_OS_WINDOWS && defined QDGE_SHARED_LIB
    #ifdef QDGE_BUILD
        #define QDGE_API __declspec(dllexport)
    #else
        #define QDGE_API __declspec(dllimport)
    #endif
#else
    #define QDGE_API
#endif

#define QDGE_NS namespace qdge {
#define QDGE_NS_END }

#define nonvirtual
#define interface class
#define singleton class
#define staticclass class

#define QDGE_COMPILER_GCC   0
#define QDGE_COMPILER_CLANG 1
#define QDGE_COMPILER_MSVC  2
#define QDGE_COMPILER_INTEL 3

#if QDGE_COMPILER == QDGE_COMPILER_MSVC
    #define QDGE_BREAK(...) QDGE_CRITICAL(__VA_ARGS__); __debugbreak();
    #define BREAK(...)      CRITICAL(__VA_ARGS__); __debugbreak();
#else
    #define QDGE_BREAK(...) QDGE_CRITICAL(__VA_ARGS__); throw std::exception();
    #define BREAK(...)      CRITICAL(__VA_ARGS__); throw std::exception();
#endif

#define BITFIELD(pos) (1 << pos)
