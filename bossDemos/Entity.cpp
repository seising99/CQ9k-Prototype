#include "Entity.h"
#include "SFML/Graphics.hpp"
#include "Game.h"

Entity::Entity(const sf::Texture &txt, float scaleX, float scaleY)
{

	sprite.setTexture(txt);
	sprite.setOrigin(
		(float)sprite.getTextureRect().width / 2, 
		(float)sprite.getTextureRect().height / 2
	);
	sprite.setScale(scaleX, scaleY);

	health = 0;
	rotation = 0;

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

int Entity::getHealth()
{
	return health;
}

void Entity::setHealth(int _health)
{
	health = _health;
}

void Entity::Draw() //TODO -- Singleton 'View' holds all entities and runs Draw()
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