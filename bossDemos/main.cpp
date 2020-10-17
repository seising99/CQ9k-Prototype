#include <SFML/Graphics.hpp>
#include "Game.h"
#include "TextureMap.h"
#include "EntityManager.h"
#include <iostream>
#include <string.h>
#include <stdlib.h>


//Create singletons
Game* Game::singleton = 0;
TextureMap* TextureMap::singleton = 0;
EntityManager* EntityManager::singleton = 0;

int main()
{

	Game::instance()->run(); //Begin the game

	return 0;

}