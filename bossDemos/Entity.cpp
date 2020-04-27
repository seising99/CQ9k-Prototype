#include "Entity.h"
#include "SFML/Graphics.hpp"
#include "Game.h"
#include "EntityManager.h"
#include "Collision.h"
#include "LivingEntity.h"

//Default Constructor -- DO NOT USE --> For Entity Manager 'Composite'
Entity::Entity()
{
	type = EntityType::Static;
	rotation = 0;
}

//Destructor -- Remove entity from list of entities, and destroy
Entity::~Entity()
{

	auto it = std::find(ENTITY_MANAGER->entities.begin(), ENTITY_MANAGER->entities.end(), this);

	if (it != ENTITY_MANAGER->entities.end())
		ENTITY_MANAGER->entities.erase(it);

}

//Constructor (Most Entities) -- Create entity given texture, position, and velocity
Entity::Entity(const sf::Texture& txt, sf::Vector2f _pos, sf::Vector2f _vel)
{

	type = EntityType::Static;

	sprite.setTexture(txt);
	sprite.setOrigin(
		(float)sprite.getTextureRect().width / 2,
		(float)sprite.getTextureRect().height / 2
	);

	pos = _pos;
	vel = _vel;

	rotation = 0;

	ENTITY_MANAGER->entities.push_back(this); //Add entity to manager

}

//Constructor (Primarily M.O.U.S.E.) -- Create entity with only texture, no position or velocity
Entity::Entity(const sf::Texture& txt)
{

	type = EntityType::Static;

	sprite.setTexture(txt);
	sprite.setOrigin(
		(float)sprite.getTextureRect().width / 2, 
		(float)sprite.getTextureRect().height / 2
	);

	rotation = 0;

	ENTITY_MANAGER->entities.push_back(this); //Add entity to manager

}

//Getters and Setters for position, velocity, rotation, scale, health, and drawing priority
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

//Drawing Priority -- Determines order sprites get drawn to the screen (larger priority is drawn towards the front)
char Entity::getPriority()
{
	return drawPriority;
}

void Entity::setPriority(char i)
{
	drawPriority = i;
}

//Check in Window -- Determine if an entity is within the current window
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

//Draw -- If entity is in window, set current position and rotation, and draw entity
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

bool Entity::checkCollision(Entity& _e1, Entity& _e2, bool pixelPerfect)
{
	
	if (_e1.sprite.getGlobalBounds().intersects(_e2.sprite.getGlobalBounds()))
	{

		if (pixelPerfect)
			return Collision::PixelPerfectTest(_e1.sprite, _e2.sprite, 127);
		else 
			return true;

	}
	else 
		return false;

}
