#include "LivingEntity.h"
#include "EntityManager.h"
#include <iostream>

float LivingEntity::getHealth() const
{
	return health;
}

void LivingEntity::setHealth(float _health)
{
	health = _health;
}

void LivingEntity::collision(LivingEntity& _e1, LivingEntity& _e2)
{

	std::cout << "COLLIDED!" << std::endl;

	_e1.damage(&_e2);
	_e2.damage(&_e1);

}