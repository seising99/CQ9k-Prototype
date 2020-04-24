#include "LivingEntity.h"
#include "EntityManager.h"

int LivingEntity::getHealth() const
{
	return health;
}

void LivingEntity::setHealth(int _health)
{
	health = _health;
}

void LivingEntity::collision(LivingEntity& _e1, LivingEntity& _e2)
{

	_e1.damage(&_e2);
	_e2.damage(&_e1);

}