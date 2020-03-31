#pragma once
#include <SFML/Graphics.hpp>

/*
*	Projectile: Objects fired by the M.O.U.S.E. to attack enemies.
*	-- Projectile abstract class stores velocity and position
*	-- Bullet, Rocket as ConcreteProjectiles
*	-- getDamage() virtual function, different projectiles deal different damage
*/

class Projectile
{

protected:

	sf::Sprite sProjectile;

	sf::Vector2f vel;
	sf::Vector2f pos;

	virtual int getDamage() const { return 0; }; //Each projectile has different damage
	virtual void setTexture() const { }; //Each projectile has different texture

public:

	Projectile(sf::Vector2f, sf::Vector2f); //Constructor for all projectiles

	void Draw();

	sf::Vector2f getVelocity() const;
	sf::Vector2f getPos() const;

	void setVelocity(sf::Vector2f);
	void setPosition(sf::Vector2f);

};

class Bullet : public Projectile
{

	void setTexture();

public:

	Bullet(sf::Vector2f, sf::Vector2f) : Projectile(pos, vel) { } ; //Calls parent constructor
	int getDamage();

};

class Rocket : public Projectile
{

	void setTexture();

public:

	Rocket(sf::Vector2f, sf::Vector2f) : Projectile(pos, vel) { }; //Calls parent constructor
	int getDamage();

};