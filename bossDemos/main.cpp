#include <SFML/Graphics.hpp>
#include "Game.h"
#include "TextureMap.h"

Game* Game::singleton = 0;
TextureMap* TextureMap::singleton = 0;

int main()
{

	Game::instance()->run();

	return 0;

}