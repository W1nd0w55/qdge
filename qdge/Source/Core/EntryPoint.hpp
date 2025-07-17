#include "App.hpp"

int main() {
    auto app = qdge::App::Create();
    app->OnInit();
    app->Run();
    app->OnCleanup();
    delete app;
}
