#include <qdge.hpp>
#include <iostream>

class Game : public com::qdge::Core::App {
public:
    void OnInit() {
        std::cout << "init\n";
    }

    void Run() {
        std::cout << "main\n";
    }

    void OnCleanup() {
        std::cout << "finally over\n";
    }
};

com::qdge::Core::App* com::qdge::Core::App::Create() {
    return new Game;
}
