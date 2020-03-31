#include "Game.h"
#include "TextureMap.h"

Game::Game()
{
	window.create(sf::VideoMode(WIDTH, HEIGHT), "CompuQuest9000 Boss Demo");
	window.setView(sf::View(sf::FloatRect(0,0,1280,720)));
	window.setMouseCursorVisible(false);
}

Game::~Game()
{
	delete singleton;
}

void Game::run()
{

	while (window.isOpen())
	{
		input();
		update();
		render();
	}

}

void Game::input()
{

    sf::Event event;
    while (window.pollEvent(event))
    {

		if (event.type == sf::Event::Closed)
			window.close();

		if (event.type == sf::Event::KeyPressed)
		{

			if (event.key.code == sf::Keyboard::Escape)
				window.close();

		}

    }

}

void Game::update()
{
	mouse.updatePositions();
}

void Game::render()
{

	window.clear();
	mouse.Draw();
	window.display();

}

sf::RenderWindow& Game::getWindow()
{
	return window;
}

Mouse& Game::getMouse()
{
	return mouse;
}