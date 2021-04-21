#include "MenuState.h"
#include "HackModeState.h"
#include "RPGState.h"
#include "Game.h"
#include "EntityManager.h"
#include "TextureMap.h"

MenuState::MenuState()
{

	option = 0;

	menu.setTexture(TEXTURES("menu"));
	menu.setScale(sf::Vector2f((float)WINDOW.getSize().x / 1920.0f, (float)WINDOW.getSize().y / 1080.0f));

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

			if (event.key.code == sf::Keyboard::R)
			{
				Game::instance()->setState(new RPGState());
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
	WINDOW.draw(menu);
	WINDOW.display();
}