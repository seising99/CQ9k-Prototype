#include "RPGState.h"
#include "Game.h"
#include "EntityManager.h"
#include "TextureMap.h"
#include <string>
#include <iostream>

RPGState::RPGState()
{
	txtFont.loadFromFile("sprites/AnonymousPro-Regular.ttf");
	displayText.setFont(txtFont);
	displayText.setPosition(20, 20);
	displayText.setFillColor(sf::Color::White);
	displayText.setCharacterSize(18);
	displayText.setLineSpacing(1.25);
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

		if (event.type == sf::Event::TextEntered)
		{
			if (event.text.unicode != 8 && event.text.unicode != 13)
				str += (char)event.text.unicode;
			else if (str.size() > 0 && event.text.unicode == 8 && str.at(str.size() - 1) != '\n')
				str.erase(str.size() - 1);
			else if (event.text.unicode == 13)
				str += "\n";
		}

	}

}

void RPGState::update()
{

	if (displayText.getGlobalBounds().intersects(sf::FloatRect((float)WINDOW.getSize().x, 0, (float)WINDOW.getSize().x, (float)WINDOW.getSize().y)))
	{
		auto it = str.begin() + str.size() - 8;
		str.insert(it, '\n');
	}

	if (displayText.getGlobalBounds().intersects(sf::FloatRect(0, (float)WINDOW.getSize().y, (float)WINDOW.getSize().x, (float)WINDOW.getSize().y)))
	{
		displayText.setPosition(sf::Vector2f(displayText.getPosition().x, displayText.getPosition().y - 18));
	}

	displayText.setString(str);

}

void RPGState::render()
{

	WINDOW.clear(sf::Color(50,5,25));
	WINDOW.draw(displayText);
	WINDOW.display();

}