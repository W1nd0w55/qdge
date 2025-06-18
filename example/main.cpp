#include <qdge.hpp>
#include <iostream>

class Game : public com::qdge::Core::App {
public:
    void OnInit() {
    }

    void Run() {
        logger->SetLevel(com::qdge::Tools::LogLevel::Trace);
        logger->SetPattern("%n [%l] at %r - %v");

        logger->Trace("This is a %s!", "message");
        logger->Debug("This is a %s!", "debug message");
        logger->Info("This is some %s!", "information");
        logger->Warn("This is a %s!", "warning");
        logger->Error("This is an %s!", "error");
        logger->Critical("This is an %s!", "oopsie!");
    }

    void OnCleanup() {
    }

private:
    com::qdge::Tools::Logger* logger = com::qdge::Tools::Logger::Create("Game");
};

com::qdge::Core::App* com::qdge::Core::App::Create() {
    return new Game;
}
