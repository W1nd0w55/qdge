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
        qdge::MouseMoveEvent exampleEvent(69, 420);
        qdge::EventDispatcher::Dispatch<qdge::MouseMoveEvent>(exampleEvent, [](qdge::MouseMoveEvent & e)
        {
            INFO(e.ToString());
            
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
