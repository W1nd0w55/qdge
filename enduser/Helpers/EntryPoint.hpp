#include "Tools/Defines.hpp"
#include "Core/App.hpp"

int main() {
    auto app = com::qdge::Core::App::Create();
    app->OnInit();
    app->Run();
    app->OnCleanup();
    delete app;
}
