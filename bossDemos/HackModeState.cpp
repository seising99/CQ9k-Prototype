#include "HackModeState.h"
#include "Game.h"
#include "EntityManager.h"

void HackModeState::input()
{
	mouse.inputHandler();
}

void HackModeState::update()
{
	ENTITY_MANAGER->update();
}

void HackModeState::render()
{
	WINDOW.clear();
	ENTITY_MANAGER->draw();
	WINDOW.display();
}