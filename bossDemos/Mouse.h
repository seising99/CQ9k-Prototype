#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Projectile.h"
#include "LivingEntity.h"

#define SLOW_ROT 250
#define FAST_ROT 500

#define SCALE_X .75f
#define SCALE_Y .75f

#define BULLET_SPEED 25

#define COOLDOWN_LEFT .1f
#define COOLDOWN_RIGHT .25f

class Mouse : public LivingEntity
{

	int rocketCount;

	bool canFire;
	
	sf::Clock cooldownClock;	//Tracks time elapsed for cooldown
	float cooldownTime;			//Determines length of cooldown

	std::vector<Projectile*> projectiles;

public:

	Mouse();
	~Mouse();

	void fireBullet();
	void fireRocket();
	void damage(LivingEntity* _e);

	std::vector<Projectile*> getProjectiles();

	void update();			//Update Model
	void inputHandler();	//Controller

	int getRocketCount() const;
	void setRocketCount(int newCount);

};