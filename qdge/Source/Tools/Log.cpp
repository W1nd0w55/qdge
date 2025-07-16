#include "pch.hpp"
#include "Log.hpp"

QDGE_NS

namespace Tools {
    Log::Logger Log::sCoreLogger = spdlog::stdout_color_mt("qdge");
    Log::Logger Log::sGameLogger = spdlog::stdout_color_mt("Game");

    void Log::Init() {
        spdlog::set_level(spdlog::level::trace);
        spdlog::set_pattern("%^%n [%l] %r: %v%$");
    }
}

QDGE_NS_END
