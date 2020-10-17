#include "Game.h"
#include "TextureMap.h"
#include "EntityManager.h"
#include "HackModeState.h"
#include "RPGState.h"
#include <time.h>
#include "Parasite.h"

//Default Constructor -- Creates and initializes game window
Game::Game()
{

<<<<<<< Updated upstream
	window.create(sf::VideoMode(sf::VideoMode::getDesktopMode().width / 1.5, sf::VideoMode::getDesktopMode().height / 1.5), "CompuQuest9000 Demo");
=======
	window.create(sf::VideoMode(unsigned int(float(sf::VideoMode::getDesktopMode().width) / 1.5f), unsigned int(float(sf::VideoMode::getDesktopMode().height) / 1.5f)), "CompuQuest9000 Demo", sf::Style::Close);
	window.setSize(sf::Vector2u(800, 600));
>>>>>>> Stashed changes
	window.setView(sf::View(sf::FloatRect(0, 0, (float)window.getSize().x, (float)window.getSize().y)));
	window.setMouseCursorVisible(true);
	window.setFramerateLimit(60);

	sf::Image icon;
	icon.loadFromFile("sprites/cmd.png");
	window.setIcon(16, 16, icon.getPixelsPtr());

	deltaTime = 0;
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

void Game::setState(GameState* newState)
{
	currentState = newState;
}