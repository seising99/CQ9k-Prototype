#pragma once
#include <SFML/Graphics.hpp>
#include "GameState.h"
#include <string.h>

class RPGState : public GameState
{

	std::string str;
	sf::Text displayText;
	sf::Font txtFont;

public:

	RPGState();

	void input();
	void update();
	void render();

};