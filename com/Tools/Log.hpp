#pragma once

#include "Tools/QualityOfCode.hpp"
#include "Tools/Defines.hpp"
#include "Core/OSSpecific.hpp"

#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>

QDGE_NS_COM

namespace Tools {
    typedef std::shared_ptr<spdlog::logger> Logger;

    staticclass QDGE_API Log {
    public:
        static void Init();
        
        static QDGE_API Logger sCoreLogger;
        static QDGE_API Logger sGameLogger;

        static std::string Format(std::string...);
    };
}

QDGE_NS_END

#if defined QDGE_DEV || defined QDGE_TESTING
    #define QDGE_TRACE(...) com::qdge::Tools::Log::sCoreLogger->trace(com::qdge::Tools::Log::Format(__VA_ARGS__))
    #define QDGE_DEBUG(...) com::qdge::Tools::Log::sCoreLogger->debug(com::qdge::Tools::Log::Format(__VA_ARGS__))
    #define QDGE_INFO(...) com::qdge::Tools::Log::sCoreLogger->info(com::qdge::Tools::Log::Format(__VA_ARGS__))

    #define TRACE(...) com::qdge::Tools::Log::sGameLogger->trace(com::qdge::Tools::Log::Format(__VA_ARGS__))
    #define DEBUG(...) com::qdge::Tools::Log::sGameLogger->debug(com::qdge::Tools::Log::Format(__VA_ARGS__))
    #define INFO(...) com::qdge::Tools::Log::sGameLogger->info(com::qdge::Tools::Log::Format(__VA_ARGS__))
#else
    #define QDGE_TRACE(...)
    #define QDGE_DEBUG(...)
    #define QDGE_INFO(...)

    #define TRACE(...)
    #define DEBUG(...)
    #define INFO(...)
#endif

#define QDGE_WARN(...) com::qdge::Tools::Log::sCoreLogger->warn(com::qdge::Tools::Log::Format(__VA_ARGS__))
#define QDGE_ERROR(...) com::qdge::Tools::Log::sCoreLogger->error(com::qdge::Tools::Log::Format(__VA_ARGS__))
#define QDGE_CRITICAL(...) com::qdge::Tools::Log::sCoreLogger->critical(com::qdge::Tools::Log::Format(__VA_ARGS__))

#define WARN(...) com::qdge::Tools::Log::sGameLogger->warn(com::qdge::Tools::Log::Format(__VA_ARGS__))
#define ERROR(...) com::qdge::Tools::Log::sGameLogger->error(com::qdge::Tools::Log::Format(__VA_ARGS__))
#define CRITICAL(...) com::qdge::Tools::Log::sGameLogger->critical(com::qdge::Tools::Log::Format(__VA_ARGS__))
