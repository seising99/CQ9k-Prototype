#pragma once
#include "Enemy.h"
#include <vector>

class Toast : public Enemy
{

	void animate();
	int frame = 0;
	int count = 0;

public:

	Toast();
	~Toast();

	void update();
	float getDamage();

};

static std::vector<Toast*> toasts;