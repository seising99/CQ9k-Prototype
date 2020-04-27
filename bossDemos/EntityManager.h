#pragma once
#include "SFML/Graphics.hpp"
#include "Entity.h"
#include "Parasite.h"
#include <vector>

#define ENTITY_MANAGER EntityManager::instance()

/*
*	EntityManager: Global object to hold, update, and draw entities to the game window
*	-- vector<Entity*> holds all current game entities, and is sorted by priority to determine what gets drawn first
*	-- Functions update() and draw() come from the Entity class, and call those respective functions on all entities
*/

class EntityManager
{

	EntityManager();
	~EntityManager();

	static EntityManager* singleton;

public:

	void update();
	void draw();

	std::vector<Entity*> entities;

	//Lazy Instantiation
	static EntityManager* instance()
	{
		if (!singleton)
			singleton = new EntityManager;
		return singleton;
	}

};