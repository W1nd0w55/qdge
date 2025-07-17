#include <qdge.hpp>
#include <iostream>

class Game: public qdge::App
{
public:
    void OnInit() override
    {
    }

    void Run() override
    {
        qdge::MouseMoveEvent event(69, 420);
        qdge::EventDispatcher dispatcher(event);
        dispatcher.Dispatch<qdge::MouseMoveEvent>([](qdge::MouseMoveEvent& e)
        {
            DEBUG(e.ToString());

            return true;
        });
    }

    void OnCleanup() override
    {
    }
};

qdge::App* qdge::App::Create()
{
    return new Game;
}
