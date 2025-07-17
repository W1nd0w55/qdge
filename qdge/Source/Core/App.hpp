#pragma once

#include "Core.hpp"

QDGE_NS

interface QDGE_API App
{
public:
    // Game definition
    static App* Create();

    nonvirtual App();
    nonvirtual ~App();

    virtual void OnInit() = 0;
    virtual void OnCleanup() = 0;
    virtual void Run() = 0;

private:
    static bool sAppExists;
};

QDGE_NS_END
