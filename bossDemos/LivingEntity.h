#pragma once
#include "Entity.h"

class LivingEntity : public Entity
{

	int health;
	bool damaged = false;

public:

	//Constructors, taken from Entity
	LivingEntity() : Entity() { health = 1; };
	LivingEntity(const sf::Texture& _txt, sf::Vector2f _pos, sf::Vector2f _vel) : Entity(_txt, _pos, _vel) { health = 1; };
	LivingEntity(const sf::Texture& _txt) : Entity(_txt) { health = 1; };
	~LivingEntity() {};

	virtual void damage(LivingEntity* _e) { _e->health -= 1; };
	virtual void kill(LivingEntity* _e) { _e->health = 0; };

	int getHealth() const;
	void setHealth(int);

	virtual void update() = 0;

	static void collision(LivingEntity&, LivingEntity&);

};