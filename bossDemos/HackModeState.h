#pragma once
#include "Mouse.h"
#include "GameState.h"
class HackModeState : public GameState
{

	Mouse mouse;

public:

	HackModeState();

	void input();
	void update();
	void render();

};