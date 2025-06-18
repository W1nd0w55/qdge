#include "App.hpp"
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

        // ...

        //OnInit();
    }
    App::~App() {
        // ...

        //OnCleanup();
        sAppExists = false;
    }
}

QDGE_NS_END
