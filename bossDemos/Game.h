#pragma once
#include <SFML/Graphics.hpp>
#include "Mouse.h"

#define WIDTH 1280
#define HEIGHT 720

#define WINDOW Game::instance()->getWindow()
#define DT Game::instance()->getTime()

/*
*	Game: The Global Game Object
*	-- Singleton ensures single global game object
*	-- Holds game's M.O.U.S.E., deltaClock/Time, and render window
*	-- Game operations split into 3 functions
*		-- Input Handling
*		-- Updating Entities
*		-- Rendering Entities
*/

class Game
{

	Game();
	~Game();

	//deltaClock and deltaTime ensure physics act the same regardless of framerate
	sf::Clock deltaClock;
	float deltaTime;

	Mouse mouse;

	static Game* singleton;

	void input();
	void update();
	void render();

	sf::RenderWindow window;

public:

	void run();

	sf::RenderWindow& getWindow();

	Mouse& getMouse();

	float getTime();

	//Lazy Instantiation
	static Game* instance()
	{
		if (!singleton)
			singleton = new Game;
		return singleton;
	}

};