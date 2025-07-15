#include "Core/App.hpp"

int main() {
    auto app = qdge::Core::App::Create();
    app->OnInit();
    app->Run();
    app->OnCleanup();
    delete app;
}
