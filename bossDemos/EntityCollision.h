#pragma once
#include "LivingEntity.h"

class EntityCollision
{

public:
	
	LivingEntity& getEntity(int _id);
	void collision(LivingEntity &, LivingEntity &);

};