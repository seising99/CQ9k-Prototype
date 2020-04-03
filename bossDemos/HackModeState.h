#pragma once
#include "Mouse.h"
#include "GameState.h"
class HackModeState : public GameState
{

	Mouse mouse;

public:
	void input();
	void update();
	void render();

};