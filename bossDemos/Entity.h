#pragma once
#include "SFML/Graphics.hpp"

#define SPEED_CONST 30

class Entity
{

	sf::Sprite sprite;

	sf::Vector2f pos;
	sf::Vector2f vel;

	float rotation;

	int health;

	char drawPriority = 0;

protected:

	sf::Vector2f getPosition();
	void setPosition(sf::Vector2f);

	sf::Vector2f getVelocity();
	void setVelocity(sf::Vector2f);

	float getRotation();
	void setRotation(float);

	sf::Vector2f getScale();
	void setScale(sf::Vector2f);

	int getHealth();
	void setHealth(int);

	void setPriority(char);

	bool checkInWindow();

public:
	Entity();
	Entity(const sf::Texture&, sf::Vector2f, sf::Vector2f);
	Entity(const sf::Texture&);
	~Entity();

	char getPriority();
	virtual void update() = 0;
	void draw();

};