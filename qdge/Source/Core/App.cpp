#include "pch.hpp"
#include "App.hpp"
#include "Tools/Log.hpp"

QDGE_NS

bool App::sAppExists = false;

App::App()
{
    Log::Init();

    if (sAppExists)
    {
        QDGE_BREAK("App already exists!");
    }
    sAppExists = true;

    QDGE_TRACE("Starting {}", "qdge::App");
}

App::~App()
{
    sAppExists = false;
}

QDGE_NS_END
