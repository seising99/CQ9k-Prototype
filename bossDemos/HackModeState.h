#pragma once
#include "Mouse.h"
#include "Enemy.h"
#include "GameState.h"
#include <vector>
class HackModeState : public GameState
{

	Mouse* mouse = nullptr;

public:

	std::vector<Enemy*> enemies;

	HackModeState();

	void input();
	void update();
	void render();

};