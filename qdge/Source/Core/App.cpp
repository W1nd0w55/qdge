#include "App.hpp"
#include "Tools/Log.hpp"
#include "Exceptions.hpp"

QDGE_NS

namespace Core {
    bool App::sAppExists = false;

    App::App() {
        if (sAppExists)
            throw Exceptions::AppExistsError();
        sAppExists = true;

        QDGE_TRACE("Starting {}", "qdge::Core::App");
    }
    App::~App() {
        sAppExists = false;
    }
}

QDGE_NS_END
