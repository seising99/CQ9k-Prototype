#pragma once
#include <SFML/Graphics.hpp>
#include "GameState.h"

class MenuState : public GameState
{

	sf::Sprite menu;

	unsigned char option;

public:

	MenuState();

	void input();
	void update();
	void render();

};