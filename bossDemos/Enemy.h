#pragma once
#include "SFML/Graphics.hpp"
#include "LivingEntity.h"

class Enemy : public LivingEntity
{

public:

	Enemy(const sf::Texture& _txt) : LivingEntity(_txt) { };
	Enemy(const sf::Texture& _txt, sf::Vector2f _pos, sf::Vector2f _vel) : LivingEntity(_txt, _pos, _vel) { };

	virtual void update() = 0; //Behavior
	virtual int getDamage() = 0;

};