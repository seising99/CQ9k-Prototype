#include "HackModeState.h"
#include "Game.h"
#include "Parasite.h"
#include "Toast.h"
#include "CD.h"
#include "EntityManager.h"

HackModeState::HackModeState()
{
	mouse = new Mouse();

	WINDOW.create(sf::VideoMode::getDesktopMode(), "CompuQuest9000 Demo", sf::Style::None);
	WINDOW.setView(sf::View(sf::FloatRect(0, 0, (float)WINDOW.getSize().x, (float)WINDOW.getSize().y)));
	WINDOW.setMouseCursorVisible(false);
	WINDOW.setFramerateLimit(60);
}

void HackModeState::input()
{

	mouse->inputHandler();

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
			if (event.key.code == sf::Keyboard::Y)
			{
				Toast* t = new Toast();
				enemies.push_back(t);
			}
			if (event.key.code == sf::Keyboard::G)
			{
				CD* c = new CD();
				enemies.push_back(c);
			}

		}

	}

}

void HackModeState::update()
{

/* -- Check for Collisions -- */

	//Check collisions for M.O.U.S.E.

	for (unsigned int i = 0; i < enemies.size(); i++)
	{

		//MOUSE Collision
		if (Entity::checkCollision(*mouse, *enemies[i], true))
		{
			mouse->kill(enemies[i]);
		}

		//Projectile Collision
		for (unsigned int j = 0; j < mouse->getProjectiles().size(); j++)
		{

			if (Entity::checkCollision(*mouse->getProjectiles()[j], *enemies[i]))
				mouse->getProjectiles()[j]->damage(enemies[i]);

		}

		//Remove dead enemies from reference vector
		if (enemies[i]->getHealth() <= 0)
		{
			auto it = std::find(enemies.begin(), enemies.end(), enemies[i]);
			if (it != enemies.end())
				enemies.erase(it);
		}

	}

	ENTITY_MANAGER->update();

}

void HackModeState::render()
{
	WINDOW.clear();
	ENTITY_MANAGER->draw();
	WINDOW.display();
}