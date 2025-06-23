#include "Log.hpp"

#include <cstdarg>

QDGE_NS_COM

namespace Tools {
    Logger Log::sCoreLogger = spdlog::stdout_color_mt("qdge");
    Logger Log::sGameLogger = spdlog::stdout_color_mt("Game");

    void Log::Init() {
        spdlog::set_level(spdlog::level::trace);
        spdlog::set_pattern("%^%n [%l] %r: %v");
    }

    std::string Log::Format(std::string str...) {
        va_list args;
        va_start(args, str);

        const size_t size = vsnprintf(0, 0, str.c_str(), args) + 1;
        char* buffer = (char*)alloca(size);
        vsnprintf(buffer, size, str.c_str(), args);
        return std::string(buffer);
    }
}

QDGE_NS_END
