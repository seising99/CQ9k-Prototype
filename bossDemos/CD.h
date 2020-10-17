#pragma once
#include "Enemy.h"
#include <vector>

class CD : public Enemy
{

	void animate();
	int frame = 0;
	int count = 0;

public:

	CD();
	~CD();

	void update();
	float getDamage();

};

static std::vector<CD*> disks;