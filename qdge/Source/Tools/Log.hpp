#pragma once

#include "Core/Core.hpp"

#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>

QDGE_NS

namespace Tools {

    staticclass QDGE_API Log {
        typedef std::shared_ptr<spdlog::logger> Logger;

    public:
        static void Init();
        
        static Logger sCoreLogger;
        static Logger sGameLogger;
    };
}

QDGE_NS_END

#if defined QDGE_DEV || defined QDGE_TESTING
    #define QDGE_TRACE(...) Tools::Log::sCoreLogger->trace(__VA_ARGS__)
    #define QDGE_DEBUG(...) Tools::Log::sCoreLogger->debug(__VA_ARGS__)
    #define QDGE_INFO(...) Tools::Log::sCoreLogger->info(__VA_ARGS__)

    #define TRACE(...) qdge::Tools::Log::sGameLogger->trace(__VA_ARGS__)
    #define DEBUG(...) qdge::Tools::Log::sGameLogger->debug(__VA_ARGS__)
    #define INFO(...) qdge::Tools::Log::sGameLogger->info(__VA_ARGS__)
#else
    #define QDGE_TRACE(...)
    #define QDGE_DEBUG(...)
    #define QDGE_INFO(...)

    #define TRACE(...)
    #define DEBUG(...)
    #define INFO(...)
#endif

#define QDGE_WARN(...) Tools::Log::sCoreLogger->warn(__VA_ARGS__)
#define QDGE_ERROR(...) Tools::Log::sCoreLogger->error(__VA_ARGS__)
#define QDGE_CRITICAL(...) Tools::Log::sCoreLogger->critical(__VA_ARGS__)

#define WARN(...) qdge::Tools::Log::sGameLogger->warn(__VA_ARGS__)
#define ERROR(...) qdge::Tools::Log::sGameLogger->error(__VA_ARGS__)
#define CRITICAL(...) qdge::Tools::Log::sGameLogger->critical(__VA_ARGS__)
