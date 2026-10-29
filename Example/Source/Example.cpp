#include "pch.hpp"
#include <Source/App.hpp>

class Example : public qdge::App
{
public:
	Example()
	{
		std::cout << "Hi from example\n";
	}

	~Example()
	{
		std::cout << "Bye from example\n";
		std::cin.get();
	}

	void Run() override
	{
		std::cout << "Working (kinda)\n";
	}
};

qdge::App* qdge::CreateApp()
{
	return new Example;
}
