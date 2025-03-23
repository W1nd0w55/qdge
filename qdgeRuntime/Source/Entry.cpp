#include "qdge"

int main(int argc, const char** argv, const char** env)
{
	auto app = Qdge::App::Create();
	app->Run();
	delete app;
}
