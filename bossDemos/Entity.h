#pragma once
#include <SFML/Graphics.hpp>

/*
*	Entity: An abstract class/interface for all game objects
*	-- Holds a sprite, along with it's position, velocity, and rotation
*	-- Holds an entities health (if applicable)
*	-- Holds an entities priority (larger priority entities are drawn towards the front of the screen)
*	-- update() and draw() to update entity attributes and draw them to the screen
*/

enum class EntityType {Static, Living, Hostile};

class Entity
{

	sf::Sprite sprite;

	sf::Vector2f pos;
	sf::Vector2f vel;

	float rotation;

	char drawPriority = 0;

protected:

	EntityType type;

	sf::Vector2f getPosition();
	void setPosition(sf::Vector2f);

	sf::Vector2f getVelocity();
	void setVelocity(sf::Vector2f);

	float getRotation();
	void setRotation(float);

	sf::Vector2f getScale();
	void setScale(sf::Vector2f);

	void setPriority(char);

	bool checkInWindow();

public:
	Entity(); //Default Constructor -- DO NOT USE
	Entity(const sf::Texture&, sf::Vector2f, sf::Vector2f); //Primary Constructor
	Entity(const sf::Texture&); //Constructor without pos/vel (primarily for M.O.U.S.E.)
	~Entity(); //Destructor

	char getPriority();
	virtual void update() = 0; //All entities must have an update() to update position, velocity, etc.
	void draw(); //All entities have a draw function, where the default updates position and rotation, and draws the entity to the screen

	static bool checkCollision(Entity&, Entity&, bool = false);

};