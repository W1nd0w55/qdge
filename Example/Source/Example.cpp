#include <Source/App.hpp>
#include <iostream>

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
	}

	void Run() override
	{
		std::cout << "Working (kinda)\n";
	}
};

int main()
{
	Example app;
	app.Run();
}
