#include "App.hpp"
#include "Tools/Log.hpp"
#include "Exceptions.hpp"

#define PLACEHOLDER_FUNCTION(name) void App::##name() { throw Exceptions::FunctionNotDefinedError(); }

QDGE_NS

namespace Core {
    bool App::sAppExists = false;

    PLACEHOLDER_FUNCTION(OnInit)
    PLACEHOLDER_FUNCTION(OnCleanup)

    App::App() {
        if (sAppExists)
            throw Exceptions::AppExistsError();
        sAppExists = true;

        QDGE_TRACE("Starting %s", "qdge::Core::App");
    }
    App::~App() {
        sAppExists = false;
    }
}

QDGE_NS_END
