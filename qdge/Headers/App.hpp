#pragma once

#include "Core.hpp"

namespace Qdge
{
    class QDGE_API App
    {
        /* The constructor and destructor are used internally.
         * For custom init and cleanup actions,
         * define OnInit() and OnCleanup().
         */

    public:
        // Define in GAME
        static App* Create();

        App();
        ~App();

        virtual void OnInit();
        virtual void OnCleanup();

        void Run();
    };
}
