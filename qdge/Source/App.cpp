#include "pch.h"
#include "App.hpp"

namespace Qdge
{
    // Add custom actions
    void App::OnInit() {}
    void App::OnCleanup() {}

    App::App()
    {
        OnInit();
    }

    App::~App()
    {
        OnCleanup();
    }

    void App::Run()
    {
    }
}
