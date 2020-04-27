#pragma once

#include "GameState.h"

class MenuState : public GameState
{

public:

	MenuState();

	void input();
	void update();
	void render();

};