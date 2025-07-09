#include "Core/App.hpp"

int main() {
    qdge::Tools::Log::Init();
    auto app = qdge::Core::App::Create();
    app->OnInit();
    app->Run();
    app->OnCleanup();
    delete app;
}
