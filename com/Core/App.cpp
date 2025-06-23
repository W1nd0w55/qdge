#include "App.hpp"
#include "Tools/Log.hpp"
#include "Exceptions.hpp"

#define PLACEHOLDER_FUNCTION(name) void App::name() { throw net::qdge::Exceptions::FunctionNotDefinedError(); }

QDGE_NS_COM

namespace Core {
    bool App::sAppExists = false;

    PLACEHOLDER_FUNCTION(OnInit)
    PLACEHOLDER_FUNCTION(OnCleanup)

    App::App() {
        if (sAppExists)
            throw net::qdge::Exceptions::AppExistsError();
        sAppExists = true;

        QDGE_TRACE("Starting %s", "com::qdge::Core::App");
    }
    App::~App() {
        sAppExists = false;
    }
}

QDGE_NS_END
