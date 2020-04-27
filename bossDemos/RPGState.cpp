#include "RPGState.h"
#include "Game.h"
#include "EntityManager.h"
#include "TextureMap.h"

RPGState::RPGState()
{

}

void RPGState::input()
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

		}

	}

}

void RPGState::update()
{

}

void RPGState::render()
{

	WINDOW.clear(sf::Color::Blue);
	WINDOW.display();

}