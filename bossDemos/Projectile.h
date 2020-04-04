#pragma once
#include <SFML/Graphics.hpp>
#include "LivingEntity.h"

#define SPEED 25

/*
*	Projectile: Objects fired by the M.O.U.S.E. to attack enemies.
*	-- Projectile abstract class stores velocity and position
*	-- Bullet, Rocket as ConcreteProjectiles
*	-- getDamage() virtual function, different projectiles deal different damage
*/

class Projectile : public LivingEntity
{

protected:

	virtual int getDamage() const { return 0; }; //Each projectile has different damage

public:

	Projectile(sf::Vector2f, sf::Vector2f, const sf::Texture&);

	void update();

	void damage(LivingEntity*);

};

class Bullet : public Projectile
{

public:

	Bullet(sf::Vector2f _pos, sf::Vector2f _vel, float _rot); //Calls parent, which calls parent, which sets proper texture

	int getDamage();

};

class Rocket : public Projectile
{

public:

	Rocket(sf::Vector2f _pos, sf::Vector2f _vel, float _rot); //Calls parent, which calls parent, which sets proper texture

	int getDamage();

};