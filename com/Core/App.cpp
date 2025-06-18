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

#if defined QDGE_DEBUG || defined QDGE_TESTING
        mLogger->SetLevel(Tools::LogLevel::Trace);
#else
        mLogger->SetLevel(Tools::LogLevel::Warn);
#endif
        mLogger->SetPattern("%n [%l] at %r - %v");

        mLogger->Trace("Starting");
    }
    App::~App() {
        mLogger->Trace("Closing");
        delete mLogger;

        sAppExists = false;
    }
}

QDGE_NS_END
