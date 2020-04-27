#include "MenuState.h"
#include "HackModeState.h"
#include "Game.h"
#include "EntityManager.h"

MenuState::MenuState()
{
	WINDOW.create(sf::VideoMode(sf::VideoMode::getDesktopMode().width / 2, sf::VideoMode::getDesktopMode().height / 2), "CompuQuest9000 Demo");
	WINDOW.setView(sf::View(sf::FloatRect(0, 0, (float)WINDOW.getSize().x, (float)WINDOW.getSize().y)));
	WINDOW.setMouseCursorVisible(true);
	WINDOW.setFramerateLimit(60);
}

void MenuState::input()
{

	sf::Event event;
	while (WINDOW.pollEvent(event))
	{

		if (event.type == sf::Event::Closed)
			WINDOW.close();

		if (event.type == sf::Event::Resized)
			WINDOW.setView(sf::View(sf::FloatRect(0, 0, (float)WINDOW.getSize().x, (float)WINDOW.getSize().y)));

		if (event.type == sf::Event::KeyPressed)
		{

			if (event.key.code == sf::Keyboard::Escape)
				WINDOW.close();

			if (event.key.code == sf::Keyboard::H)
			{
				Game::instance()->setState(new HackModeState());
			}

		}

	}

}

void MenuState::update()
{

}

void MenuState::render()
{
	WINDOW.clear();
	WINDOW.display();
}