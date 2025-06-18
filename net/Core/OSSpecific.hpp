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
