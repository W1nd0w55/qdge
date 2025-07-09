#include <qdge.hpp>
#include <iostream>

class Game: public qdge::Core::App {
public:
    void OnInit() override {
    }

    void Run() override {
        TRACE("This is a %s!", "message");
        DEBUG("This is a %s!", "debug message");
        INFO("This is some %s!", "info");
        WARN("This is a %s!", "warning");
        ERROR("This is an %s!", "error");
        CRITICAL("This is an %s!", "oopsie!!");
    }

    void OnCleanup() override {
    }
};

qdge::Core::App* qdge::Core::App::Create() {
    return new Game;
}
