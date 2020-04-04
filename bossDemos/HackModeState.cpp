#include "HackModeState.h"
#include "Game.h"
#include "EntityManager.h"

HackModeState::HackModeState()
{
	WINDOW.create(sf::VideoMode(1920,1080), "CompuQuest9000 Demo", sf::Style::Fullscreen);
	WINDOW.setView(sf::View(sf::FloatRect(0, 0, (float)WINDOW.getSize().x, (float)WINDOW.getSize().y)));
	WINDOW.setMouseCursorVisible(false);
	WINDOW.setFramerateLimit(60);
}

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