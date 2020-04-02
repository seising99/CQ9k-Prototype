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

protected:

	virtual void update() = 0;

	sf::Vector2f getPosition();
	void setPosition(sf::Vector2f);

	sf::Vector2f getVelocity();
	void setVelocity(sf::Vector2f);

	float getRotation();
	void setRotation(float);

	int getHealth();
	void setHealth(int);

	bool checkInWindow();

public:
	Entity(const sf::Texture&, float scaleX = 1, float scaleY = 1);

	void Draw();

};