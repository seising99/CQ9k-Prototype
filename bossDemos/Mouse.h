#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Projectile.h"
#include "Entity.h"

class Mouse : public Entity
{

	int rocketCount;

	bool canFire;
	sf::Clock cooldown;

	std::vector<Projectile*> projectiles;

public:

	Mouse();
	~Mouse();

	void fireBullet();
	void fireRocket();

	std::vector<Projectile*> getProjectiles();

	void update();	//Update Model
	void inputHandler();	//Controller
	//void Draw();			//Update View

	int getRocketCount() const;
	void setRocketCount(int newCount);

};