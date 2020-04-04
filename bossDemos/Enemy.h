#pragma once
#include "LivingEntity.h"

class Enemy : public LivingEntity
{

public:
	virtual void update() = 0;

};