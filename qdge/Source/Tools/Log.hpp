#pragma once

#include "Core/Core.hpp"

#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>

QDGE_NS

staticclass QDGE_API Log {
    typedef std::shared_ptr<spdlog::logger> Logger;

public:
    static void Init();
    
    static Logger sCoreLogger;
    static Logger sGameLogger;
};

QDGE_NS_END

#if defined QDGE_DEV || defined QDGE_TESTING
    #define QDGE_TRACE(...) Log::sCoreLogger->trace(__VA_ARGS__)
    #define QDGE_DEBUG(...) Log::sCoreLogger->debug(__VA_ARGS__)
    #define QDGE_INFO(...) Log::sCoreLogger->info(__VA_ARGS__)

    #define TRACE(...) qdge::Log::sGameLogger->trace(__VA_ARGS__)
    #define DEBUG(...) qdge::Log::sGameLogger->debug(__VA_ARGS__)
    #define INFO(...) qdge::Log::sGameLogger->info(__VA_ARGS__)
#else
    #define QDGE_TRACE(...)
    #define QDGE_DEBUG(...)
    #define QDGE_INFO(...)

    #define TRACE(...)
    #define DEBUG(...)
    #define INFO(...)
#endif

#define QDGE_WARN(...) Log::sCoreLogger->warn(__VA_ARGS__)
#define QDGE_ERROR(...) Log::sCoreLogger->error(__VA_ARGS__)
#define QDGE_CRITICAL(...) Log::sCoreLogger->critical(__VA_ARGS__)

#define WARN(...) qdge::Log::sGameLogger->warn(__VA_ARGS__)
#define ERROR(...) qdge::Log::sGameLogger->error(__VA_ARGS__)
#define CRITICAL(...) qdge::Log::sGameLogger->critical(__VA_ARGS__)
