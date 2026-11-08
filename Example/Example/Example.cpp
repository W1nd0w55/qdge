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
		byte a = 1;
		ubyte b = 2;
		short c = 3;
		ushort d = 4;
		int e = 5;
		uint f = 6;
		long g = 7;
		ulong h = 8;
		
		std::cout
			<< std::format("{} {} {} {} {} {} {} {}", a, b, c, d, e, f, g, h)
			<< std::endl;
	}
};

qdge::App* qdge::CreateApp()
{
	return new Example;
}
