#include "pch.hpp"
#include <Source/App.hpp>

class Example : public qdge::App
{
public:
	Example()
	{
	}

	~Example()
	{
		std::cin.get();
	}

	void Run() override
	{
		std::cout << "Байдын\n";
	}
};

qdge::App* qdge::CreateApp()
{
	return new Example;
}
