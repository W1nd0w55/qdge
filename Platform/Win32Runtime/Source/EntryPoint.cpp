#include "pch.hpp"
#include <Source/App.hpp>

int WINAPI WinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ PSTR, _In_ int)
{
	if (!AllocConsole()) return 1;

	FILE* fp;
	freopen_s(&fp, "CONOUT$", "w", stdout);
	freopen_s(&fp, "CONOUT$", "w", stderr);
	freopen_s(&fp, "CONIN$", "r", stdin);

	SetConsoleOutputCP(CP_UTF8);
	SetConsoleCP(CP_UTF8);

	auto app = qdge::CreateApp();
	app->Run();
	delete app;

	FreeConsole();
	return 0;
}

