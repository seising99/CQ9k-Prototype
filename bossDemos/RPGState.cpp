#include "RPGState.h"
#include "Game.h"
#include "EntityManager.h"
#include "TextureMap.h"
#include <string>
#include <iostream>

#define PRINT str +=

RPGState::RPGState()
{
	txtFont.loadFromFile("sprites/AnonymousPro-Regular.ttf");
	displayText.setFont(txtFont);
	displayText.setPosition(20, 20);
	displayText.setFillColor(sf::Color::Green);
	displayText.setCharacterSize(18);
	displayText.setLineSpacing(1.25);
	PRINT("Welcome to CompuQuest9000! This is the terminal.\n>> ");
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
			if (event.key.code == sf::Keyboard::Up)
				displayText.setPosition(sf::Vector2f(displayText.getPosition().x, displayText.getPosition().y + 18));
			if (event.key.code == sf::Keyboard::Down)
				displayText.setPosition(sf::Vector2f(displayText.getPosition().x, displayText.getPosition().y - 18));

		}

		if (event.type == sf::Event::TextEntered)
		{
			if (event.text.unicode != 8 && event.text.unicode != 13 && (!displayText.getGlobalBounds().intersects(sf::FloatRect((float)WINDOW.getSize().x - 36, 0, (float)WINDOW.getSize().x - 36, (float)WINDOW.getSize().y))))
				PRINT((char)event.text.unicode);
			else if (str.size() > 0 && event.text.unicode == 8 && str.at(str.size() - 4) != '\n')
				str.erase(str.size() - 1);
			else if (event.text.unicode == 13)
				PRINT("\n>> ");
		}

	}

}

void RPGState::update()
{

	if(displayText.getGlobalBounds().intersects(sf::FloatRect((float)WINDOW.getSize().x - 36, 0, (float)WINDOW.getSize().x - 36, (float)WINDOW.getSize().y)))
		str.erase(str.size() - 1);

	if (displayText.getGlobalBounds().intersects(sf::FloatRect(0, (float)WINDOW.getSize().y, (float)WINDOW.getSize().x, (float)WINDOW.getSize().y)))
	{
		displayText.setPosition(sf::Vector2f(displayText.getPosition().x, displayText.getPosition().y - 18));
	}

	displayText.setString(str);

}

void RPGState::render()
{

	WINDOW.clear(sf::Color::Black);
	WINDOW.draw(displayText);
	WINDOW.display();

}