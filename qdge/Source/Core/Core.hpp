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

#define QDGE_NULL 0

#define nonvirtual
#define interface class
#define singleton class
#define staticclass class
