#pragma once

#include "Tools/QualityOfCode.hpp"
#include "Tools/Defines.hpp"
#include "Core/OSSpecific.hpp"

#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>

QDGE_NS_COM

namespace Tools {
    class Logger {
    public:
        Logger();
        ~Logger();

        void SetLevel(spdlog::level::level_enum);
        void SetPattern(std::string);

        void Trace(std::string...);
        void Debug(std::string...);
        void Info(std::string...);
        void Warning(std::string...);
        void Error(std::string...);
        void Critical(std::string...);

    private:
        std::shared_ptr<spdlog::logger> mLogger;
        static std::string Format(std::string, va_list);
    };
}

QDGE_NS_END
