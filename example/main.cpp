#include <qdge.hpp>
#include <iostream>

class Game: public qdge::Core::App {
public:
    void OnInit() override {
    }

    void Run() override {
        TRACE("This is a {}!", "message");
        DEBUG("This is a {}!", "debug message");
        INFO("This is some {}!", "info");
        WARN("This is a {}!", "warning");
        ERROR("This is an {}!", "error");
        CRITICAL("This is an {}!", "oopsie!!");
    }

    void OnCleanup() override {
    }
};

qdge::Core::App* qdge::Core::App::Create() {
    return new Game;
}
