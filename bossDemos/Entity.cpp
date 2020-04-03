#include "Entity.h"
#include "SFML/Graphics.hpp"
#include "Game.h"
#include "EntityManager.h"
#include <algorithm>

//Default Constructor -- DO NOT USE --> For Entity Manager 'Composite'
Entity::Entity()
{
	health = 0;
	rotation = 0;

}

//Destructor -- Remove entity from list of entities, and destroy
Entity::~Entity()
{
	ENTITY_MANAGER->getEntities()->erase(
		std::remove(ENTITY_MANAGER->getEntities()->begin(), ENTITY_MANAGER->getEntities()->end(), this), 
		ENTITY_MANAGER->getEntities()->end());
}

Entity::Entity(const sf::Texture& txt, sf::Vector2f _pos, sf::Vector2f _vel)
{

	sprite.setTexture(txt);
	sprite.setOrigin(
		(float)sprite.getTextureRect().width / 2,
		(float)sprite.getTextureRect().height / 2
	);

	pos = _pos;
	vel = _vel;

	health = 0;
	rotation = 0;

	ENTITY_MANAGER->getEntities()->push_back(this);

}

Entity::Entity(const sf::Texture& txt)
{

	sprite.setTexture(txt);
	sprite.setOrigin(
		(float)sprite.getTextureRect().width / 2, 
		(float)sprite.getTextureRect().height / 2
	);

	health = 0;
	rotation = 0;

	ENTITY_MANAGER->getEntities()->push_back(this);

}

//Getters and Setters for POS, VEL, and ROT
sf::Vector2f Entity::getPosition()
{
	return pos;
}

void Entity::setPosition(sf::Vector2f _pos)
{
	pos = _pos;
}

sf::Vector2f Entity::getVelocity()
{
	return vel;
}

void Entity::setVelocity(sf::Vector2f _vel)
{
	vel = _vel;
}

float Entity::getRotation()
{
	return rotation;
}

void Entity::setRotation(float _rotation)
{
	rotation = _rotation;
}

sf::Vector2f Entity::getScale()
{
	return sprite.getScale();
}

void Entity::setScale(sf::Vector2f _scale)
{
	sprite.setScale(_scale);
}

int Entity::getHealth()
{
	return health;
}

void Entity::setHealth(int _health)
{
	health = _health;
}

char Entity::getPriority()
{
	return drawPriority;
}

void Entity::setPriority(char i)
{
	drawPriority = i;
}

bool Entity::checkInWindow()
{
	sf::FloatRect currentView(
		WINDOW.getView().getCenter().x - WINDOW.getView().getSize().x / 2, 
		WINDOW.getView().getCenter().y - WINDOW.getView().getSize().y / 2, 
		WINDOW.getView().getSize().x, WINDOW.getView().getSize().y
	);

	if (currentView.contains(pos.x, pos.y)) return true;
	else return false;

}

void Entity::draw() //TODO -- Singleton 'View' holds all entities and runs Draw()
{

	if (checkInWindow())
	{

		//Update View
		sprite.setPosition(pos);
		sprite.setRotation(rotation);

		//Draw View
		WINDOW.draw(sprite);

	}

}