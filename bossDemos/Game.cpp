#include "Game.h"
#include "TextureMap.h"
#include "EntityManager.h"
#include "HackModeState.h"
#include <time.h>
#include "Parasite.h"

//Default Constructor -- Creates and initializes game window
Game::Game()
{

	window.create(sf::VideoMode(WIDTH, HEIGHT), "CompuQuest9000 Boss Demo");
	window.setView(sf::View(sf::FloatRect(0,0, (float)window.getSize().x, (float)window.getSize().y)));
	window.setMouseCursorVisible(false);
	deltaTime = 0;
	window.setFramerateLimit(60);

	sf::Image icon;
	icon.loadFromFile("sprites/icon.png");
	window.setIcon(32,32, icon.getPixelsPtr());

	currentState = nullptr;

	srand((unsigned int)time(0));

}

//Destructor -- delete singleton
Game::~Game()
{
	delete singleton;
	delete currentState;
}

//Return deltaTime
float Game::getTime()
{
	return deltaTime;
}

//Run -- Runs game in a loop
void Game::run()
{

	currentState = new HackModeState();

	while (window.isOpen())
	{

		input();
		update();
		render();

		deltaTime = deltaClock.restart().asSeconds();

	}

}

//Input Handler -- Handles Input! -- Calls current state's input handler, and checks for window events (Controller)
void Game::input()
{

	currentState->input();

}

//Update -- Update State (Model)
void Game::update()
{
	currentState->update();
}

//Render -- Clear window, draw sprites, display (View)
void Game::render()
{
	currentState->render();
}

//Get Window and Get MOUSE
sf::RenderWindow& Game::getWindow()
{
	return window;
}

GameState* Game::getState()
{
	return currentState;
}