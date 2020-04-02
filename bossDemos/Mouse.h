#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Projectile.h"

class Mouse
{

	sf::Vector2f position;

	float angle;
	int rocketCount;

	sf::Sprite sMouse;

	std::vector<Projectile*> projectiles;

public:

	Mouse();
	~Mouse();

	void fireBullet();
	void fireRocket();

	sf::Vector2f getPosition();

	std::vector<Projectile*> getProjectiles();

	void updatePositions();	//Update Model
	void inputHandler();	//Controller
	void Draw();			//Update View

	bool checkInWindow();

	int getRocketCount() const;
	void setRocketCount(int newCount);

	float getAngle() const;
	void setAngle(float newAngle);

	sf::Sprite getSprite();

};