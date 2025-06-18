#pragma once

#include "Tools/QualityOfCode.hpp"
#include "Tools/Defines.hpp"
#include "Core/OSSpecific.hpp"

QDGE_NS_COM

namespace Core {
    class QDGE_API App {
    public:
        // Game definition
        static App* Create();

        nonvirtual App();
        nonvirtual ~App();
        virtual void OnInit();
        virtual void OnCleanup();
        virtual void Run() = QDGE_NULL;

    private:
        static bool sAppExists;
    };
}

QDGE_NS_END
