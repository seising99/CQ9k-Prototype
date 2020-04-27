#pragma once
#include <SFML/Graphics.hpp>
#include "GameState.h"

#define WIDTH 1280
#define HEIGHT 720

#define WINDOW Game::instance()->getWindow()
#define DT Game::instance()->getTime()
#define GAME_STATE Game::instance()->getState()

/*
*	Game: The Global Game Object
*	-- Singleton ensures single global game object
*	-- Game operations split into 3 functions
*		-- Input Handling
*		-- Updating Entities
*		-- Rendering Entities
*/

class Game
{

	Game();
	~Game();

	GameState* currentState;

	//deltaClock and deltaTime ensure physics act the same regardless of framerate
	sf::Clock deltaClock;
	float deltaTime;

	static Game* singleton;

	void input();
	void update();
	void render();

	sf::RenderWindow window;

public:

	void run();

	sf::RenderWindow& getWindow();
	GameState* getState();

	float getTime();

	//Lazy Instantiation
	static Game* instance()
	{
		if (!singleton)
			singleton = new Game;
		return singleton;
	}

};