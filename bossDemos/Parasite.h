#pragma once
#include "Enemy.h"
#include <vector>

#define DT_CONST 35
#define ACC_WEIGHT 1.0f
#define SEP_WEIGHT 1.0f
#define VEL_WEIGHT 4.0f
#define RAND_WEIGHT 1.0f

class Parasite : public Enemy
{

	sf::Vector2f getAlign();
	sf::Vector2f getSeparation();

public:

	Parasite();
	~Parasite();

	void update();
	float getDamage();

};

//Parasites stored in static vector
static std::vector<Parasite*> parasites;