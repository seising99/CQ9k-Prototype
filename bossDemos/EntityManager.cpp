#include "EntityManager.h"

//Default Constructor
EntityManager::EntityManager() {}

//Destructor -- delete all remaining entities
EntityManager::~EntityManager()
{
	for (unsigned int i = 0; i < entities.size(); i++)
		delete entities[i];
}

//Update -- update all entities
void EntityManager::update()
{

	for (unsigned int i = 0; i < entities.size(); i++)
		entities[i]->update();

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

	for (unsigned int i = 0; i < entities.size(); i++)
		entities[i]->draw();

}