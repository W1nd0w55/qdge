#include "qdge"

#ifdef QDGERT_USE_WINMAIN
#include <Windows.h>

int WINAPI WinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPSTR lpCmdLine,
	_In_ int nShowCmd)

#else

int main(int argc,
	const char** argv,
	const char** env)

#endif
{
	auto app = Qdge::App::Create();
	app->Run();
	delete app;
}
