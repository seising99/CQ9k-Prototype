#pragma once

#include "GameState.h"

class RPGState : public GameState
{

public:

	RPGState();

	void input();
	void update();
	void render();

};