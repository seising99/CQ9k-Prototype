#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Projectile.h"
#include "Entity.h"

#define SLOW_ROT 250
#define FAST_ROT 500

#define SCALE_X .75f
#define SCALE_Y .75f

#define BULLET_SPEED 25

#define COOLDOWN_TIME .1

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