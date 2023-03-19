#include <SFML/Graphics.hpp>
#include "settings.h"
#include "meteor.h"
#include "game.h"
using namespace sf;

int main()
{
	srand(time(0));
	Game game;
	game.play();

	return 0;
}