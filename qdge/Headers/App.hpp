#pragma once

#include "Core.hpp"

namespace Qdge
{
    class QDGE_API App
    {
    public:
        // Define in GAME
        static App* Create();

        App();
        ~App();

        void Run();
    };
}
