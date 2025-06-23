#include <qdge.hpp>
#include <iostream>

class Game: public com::qdge::Core::App {
public:
    void OnInit() {
    }

    void Run() {
        TRACE("This is a %s!", "message");
        DEBUG("This is a %s!", "debug message");
        INFO("This is some %s!", "info");
        WARN("This is a %s!", "warning");
        ERROR("This is an %s!", "error");
        CRITICAL("This is an %s!", "oopsie!!");
    }

    void OnCleanup() {
    }
};

com::qdge::Core::App* com::qdge::Core::App::Create() {
    return new Game;
}
