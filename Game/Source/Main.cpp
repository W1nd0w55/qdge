#include <qdge>

class Game : public Qdge::App
{
};

Qdge::App* Qdge::App::Create()
{
	return new Game();
}
