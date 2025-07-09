#pragma once

#include "Core/Core.hpp"

QDGE_NS

namespace Core {
    class QDGE_API App {
    public:
        // Game definition
        static App* Create();

        nonvirtual App();
        nonvirtual ~App();
        virtual void OnInit() = QDGE_NULL;
        virtual void OnCleanup() = QDGE_NULL;
        virtual void Run() = QDGE_NULL;

    private:
        static bool sAppExists;
    };
}

QDGE_NS_END
