#include <qdge.hpp>
#include <iostream>

class Game: public qdge::Core::App {
public:
    void OnInit() override {
    }

    void Run() override {
        using namespace qdge::Events;

        MouseMoveEvent exampleEvent(69, 420);
        EventDispatcher::Dispatch<MouseMoveEvent>(exampleEvent, [](MouseMoveEvent& e) {
            INFO(e.ToString());
            
            return true;
        });
    }

    void OnCleanup() override {
    }
};

qdge::Core::App* qdge::Core::App::Create() {
    return new Game;
}
