#include "pch.hpp"
#include <qdgeCore.hpp>

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
