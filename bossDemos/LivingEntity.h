#pragma once
#include "EntityManager.h"

class LivingEntity : public Entity
{

	int health;

public:

	//Constructors, taken from Entity
	LivingEntity() : Entity() { health = 1;  };
	LivingEntity(const sf::Texture& _txt, sf::Vector2f _pos, sf::Vector2f _vel) : Entity(_txt, _pos, _vel) { health = 1; };
	LivingEntity(const sf::Texture& _txt) : Entity(_txt) { health = 1; };
	~LivingEntity() {};

	virtual void damage(LivingEntity* _e) { _e->health -= 1; };

	int getHealth() const;
	void setHealth(int);

	virtual void update() = 0;


};