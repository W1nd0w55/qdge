#include "pch.hpp"
#include <Source/App.hpp>

int WINAPI wWinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ PWSTR, _In_ int)
{
	if (!AllocConsole()) return 1;

	FILE* fp;
	freopen_s(&fp, "CONOUT$", "w", stdout);
	freopen_s(&fp, "CONOUT$", "w", stderr);
	freopen_s(&fp, "CONIN$", "r", stdin);

	auto app = qdge::CreateApp();
	app->Run();
	delete app;

	FreeConsole();
	return 0;
}

