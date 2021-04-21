#pragma once
#include "Entity.h"

/*
*	LivingEntity: An abstract class/interface for all living game objects
*	-- Extends Entity, giving living entities all the same properties as regular entities
*	-- Holds health and damage
*	-- Damage and kill functions to set another entity's health
*	-- collision() to detect when two living entities collide
*/

class LivingEntity : public Entity
{

	float health;

public:

	//Constructors, taken from Entity
	LivingEntity() : Entity() { type = EntityType::Living; health = 1; };
	LivingEntity(const sf::Texture& _txt, sf::Vector2f _pos, sf::Vector2f _vel) : Entity(_txt, _pos, _vel) { type = EntityType::Living; health = 1; };
	LivingEntity(const sf::Texture& _txt) : Entity(_txt) { type = EntityType::Living;  health = 1; };
	~LivingEntity() {};
	
	virtual float getDamage() { return 0; };
	virtual void damage(LivingEntity* _e) { _e->health -= getDamage(); };
	static void kill(LivingEntity* _e) { _e->health = 0; };

	float getHealth() const;
	void setHealth(float);

	virtual void update() = 0;

	static void collision(LivingEntity&, LivingEntity&);

};