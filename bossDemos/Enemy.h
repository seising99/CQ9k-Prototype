#pragma once
#include "SFML/Graphics.hpp"
#include "LivingEntity.h"

class Enemy : public LivingEntity
{

public:

	Enemy(const sf::Texture& _txt) : LivingEntity(_txt) { type = EntityType::Hostile; };
	Enemy(const sf::Texture& _txt, sf::Vector2f _pos, sf::Vector2f _vel) : LivingEntity(_txt, _pos, _vel) { type = EntityType::Hostile; };

	virtual void update() = 0; //Behavior
	virtual float getDamage() = 0;

};