#pragma once

#include "Tools/QualityOfCode.hpp"
#include "Tools/Defines.hpp"
#include "Core/OSSpecific.hpp"

#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>

QDGE_NS_COM

namespace Tools {
    enum class QDGE_API LogLevel {
        None = spdlog::level::off,
        Trace = spdlog::level::trace,
        Debug = spdlog::level::debug,
        Info = spdlog::level::info,
        Warn = spdlog::level::warn,
        Error = spdlog::level::err,
        Critical = spdlog::level::critical
    };

    class QDGE_API Logger {
    public:
        Logger(std::string);

        void SetLevel(LogLevel);
        void SetPattern(std::string);
        void SetName(std::string);

        void Trace(std::string...);
        void Debug(std::string...);
        void Info(std::string...);
        void Warn(std::string...);
        void Error(std::string...);
        void Critical(std::string...);

        inline static Logger* Create(std::string name) {
            return new Logger(name);
        }

    private:
        std::shared_ptr<spdlog::logger> mLogger;
        static std::string Format(std::string, va_list);
    };
}

QDGE_NS_END
