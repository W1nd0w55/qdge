#include "Logger.hpp"

#include <cstdarg>

#define LOG_FUNCTION(func, spdlogFunc) void Logger::func(std::string str...) { va_list args; \
    va_start(args, str); \
    mLogger->spdlogFunc(Format(str, args)); }

QDGE_NS_COM

namespace Tools {
    Logger::Logger(std::string name) 
        : mLogger(spdlog::stdout_color_mt(name)) {
    }

    void Logger::SetLevel(LogLevel level) {
        mLogger->set_level((spdlog::level::level_enum)level);
    }

    void Logger::SetPattern(std::string pattern) {
        mLogger->set_pattern(pattern);
    }

    std::string Logger::Format(std::string str, va_list args) {
        const size_t size = vsnprintf(0, 0, str.c_str(), args) + 1;
        char* buffer = (char*)alloca(size);
        vsnprintf(buffer, size, str.c_str(), args);
        return std::string(buffer);
    }

    LOG_FUNCTION(Trace, trace)
    LOG_FUNCTION(Debug, debug)
    LOG_FUNCTION(Info, info)
    LOG_FUNCTION(Warn, warn)
    LOG_FUNCTION(Error, error)
    LOG_FUNCTION(Critical, critical)
}

QDGE_NS_END
