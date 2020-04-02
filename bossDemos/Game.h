#pragma once
#include <SFML/Graphics.hpp>
#include "Mouse.h"

#define WIDTH 1280
#define HEIGHT 720

#define WINDOW Game::instance()->getWindow()
#define DT Game::instance()->getTime()
class Game
{

private:

	Game();
	~Game();

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

	static Game* instance()
	{
		if (!singleton)
			singleton = new Game;
		return singleton;
	}

};