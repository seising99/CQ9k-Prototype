#include "Game.h"
#include "TextureMap.h"
#include "EntityManager.h"

//Default Constructor -- Creates and initializes game window
Game::Game()
{
	window.create(sf::VideoMode(WIDTH, HEIGHT), "CompuQuest9000 Boss Demo");
	window.setView(sf::View(sf::FloatRect(0,0, (float)window.getSize().x, (float)window.getSize().y)));
	window.setMouseCursorVisible(false);
	deltaTime = 0;
	window.setFramerateLimit(60);
}

//Destructor -- delete singleton
Game::~Game()
{
	delete singleton;
}

//Return deltaTime
float Game::getTime()
{
	return deltaTime;
}

//Run -- Runs game in a loop
void Game::run()
{

	while (window.isOpen())
	{

		input();
		update();
		render();

		deltaTime = deltaClock.restart().asSeconds();

	}

}

//Input Handler -- Handles Input! -- Calls MOUSE's input handler, and checks for window events (Controller)
void Game::input()
{

	mouse.inputHandler();

    sf::Event event;
    while (window.pollEvent(event))
    {

		if (event.type == sf::Event::Closed)
			window.close();

		if(event.type == sf::Event::Resized)
			window.setView(sf::View(sf::FloatRect(0, 0, (float)window.getSize().x, (float)window.getSize().y)));

		if (event.type == sf::Event::KeyPressed)
		{

			if (event.key.code == sf::Keyboard::Escape)
				window.close();

		}

    }

}

//Update -- Update Entities (Model)
void Game::update()
{
	ENTITY_MANAGER->update();
}

//Render -- Clear window, draw sprites, display (View)
void Game::render()
{

	window.clear();
	ENTITY_MANAGER->draw();
	window.display();

}

//Get Window and Get MOUSE
sf::RenderWindow& Game::getWindow()
{
	return window;
}

Mouse& Game::getMouse()
{
	return mouse;
}