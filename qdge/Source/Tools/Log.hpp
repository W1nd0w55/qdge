#pragma once

#include "Core/Core.hpp"

#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>

QDGE_NS

namespace Tools {
    typedef std::shared_ptr<spdlog::logger> Logger;

    staticclass QDGE_API Log {
    public:
        static void Init();
        
        static Logger sCoreLogger;
        static Logger sGameLogger;

        static std::string Format(std::string...);
    };
}

QDGE_NS_END

#if defined QDGE_DEV || defined QDGE_TESTING
    #define QDGE_TRACE(...) Tools::Log::sCoreLogger->trace(Tools::Log::Format(__VA_ARGS__))
    #define QDGE_DEBUG(...) Tools::Log::sCoreLogger->debug(Tools::Log::Format(__VA_ARGS__))
    #define QDGE_INFO(...) Tools::Log::sCoreLogger->info(Tools::Log::Format(__VA_ARGS__))

    #define TRACE(...) qdge::Tools::Log::sGameLogger->trace(qdge::Tools::Log::Format(__VA_ARGS__))
    #define DEBUG(...) qdge::Tools::Log::sGameLogger->debug(qdge::Tools::Log::Format(__VA_ARGS__))
    #define INFO(...) qdge::Tools::Log::sGameLogger->info(qdge::Tools::Log::Format(__VA_ARGS__))
#else
    #define QDGE_TRACE(...)
    #define QDGE_DEBUG(...)
    #define QDGE_INFO(...)

    #define TRACE(...)
    #define DEBUG(...)
    #define INFO(...)
#endif

#define QDGE_WARN(...) Tools::Log::sCoreLogger->warn(Tools::Log::Format(__VA_ARGS__))
#define QDGE_ERROR(...) Tools::Log::sCoreLogger->error(Tools::Log::Format(__VA_ARGS__))
#define QDGE_CRITICAL(...) Tools::Log::sCoreLogger->critical(Tools::Log::Format(__VA_ARGS__))

#define WARN(...) qdge::Tools::Log::sGameLogger->warn(qdge::Tools::Log::Format(__VA_ARGS__))
#define ERROR(...) qdge::Tools::Log::sGameLogger->error(qdge::Tools::Log::Format(__VA_ARGS__))
#define CRITICAL(...) qdge::Tools::Log::sGameLogger->critical(qdge::Tools::Log::Format(__VA_ARGS__))
