#include <qdge>
#include <iostream>

class Game : public Qdge::App
{
public:
	Game()
	{
		printf("ebrb");
	}
};

Qdge::App* Qdge::App::Create()
{
	return new Game();
}
