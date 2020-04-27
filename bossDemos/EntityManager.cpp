#include "EntityManager.h"
#include "Parasite.h"

//Default Constructor
EntityManager::EntityManager() {}

//Destructor -- delete all remaining entities
EntityManager::~EntityManager()
{
	for (auto&& e : entities)
		delete e;
}

//Update -- update all entities
void EntityManager::update()
{
	for (auto&& e : entities)
		e->update();
}

//Draw -- sort entity vector, and draw all entities to the screen
void EntityManager::draw()
{

	//Sort entity vector based on priority number. Higher priorities get drawn later (towards the front of the screen)
	std::sort(entities.begin(), entities.end(),[]
		(Entity * a, Entity * b)
	{
		return a->getPriority() < b->getPriority();
	});

	for (auto&& e : entities)
		e->draw();

}