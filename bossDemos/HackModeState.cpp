#include "HackModeState.h"
#include "Game.h"
#include "EntityManager.h"
#include <iostream>

HackModeState::HackModeState()
{
	WINDOW.create(sf::VideoMode::getDesktopMode(), "CompuQuest9000 Demo", sf::Style::Fullscreen);
	WINDOW.setView(sf::View(sf::FloatRect(0, 0, (float)WINDOW.getSize().x, (float)WINDOW.getSize().y)));
	WINDOW.setMouseCursorVisible(false);
	WINDOW.setFramerateLimit(60);
}

void HackModeState::input()
{

	mouse.inputHandler();

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

			if (event.key.code == sf::Keyboard::T)
			{
				Parasite* p = new Parasite();
				enemies.push_back(p);
			}

		}

	}

}

void HackModeState::update()
{

	ENTITY_MANAGER->update();

/* -- Check for Collisions -- */

	//Check collisions for M.O.U.S.E.

	for (Enemy* e : enemies)
	{

		//MOUSE Collision
		if (Entity::checkCollision(mouse, *e, true))
		{
			mouse.kill(e);
		}

		//Projectile Collision
		for (Projectile* p : mouse.getProjectiles())
		{

			if (Entity::checkCollision(*p, *e))
				p->damage(e);


		}

		//Remove dead enemies from storage vector
		if (e->getHealth() <= 0)
		{
			auto it = std::find(enemies.begin(), enemies.end(), e);
			enemies.erase(it);
		}

	}

}

void HackModeState::render()
{
	WINDOW.clear();
	ENTITY_MANAGER->draw();
	WINDOW.display();
}