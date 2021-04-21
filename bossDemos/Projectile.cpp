#include "Projectile.h"
#include "TextureMap.h"
#include "Game.h"

//Projectile Constructor -- Calls Entity Constructor with appropriate texture, position, and velocity
Projectile::Projectile(sf::Vector2f _pos, sf::Vector2f _vel, const sf::Texture& txt): LivingEntity(txt, _pos, _vel) {}

Projectile::~Projectile()
{

}

//Bullet Constructor -- Calls Projectile Constructor, and sets appropriate scale
Bullet::Bullet(sf::Vector2f _pos, sf::Vector2f _vel, float _rot) : Projectile(_pos, _vel, TEXTURES("bullet"))
{ 
	setScale(sf::Vector2f(0.5f, 0.5f)); 
	setRotation(_rot);
}

//Rocket Constructor -- Calls Projectile Constructor, and sets appropriate scale
Rocket::Rocket(sf::Vector2f _pos, sf::Vector2f _vel, float _rot) : Projectile(_pos, _vel, TEXTURES("rocket"))
{
	setScale(sf::Vector2f(1.0f, 1.0f));
	setRotation(_rot);
}

//Update Position -- Calculate new position for projectile based on current position and velocity, and update model (sprite)
void Projectile::update()
{

	setPosition(getPosition() + (getVelocity() * (DT * SPEED)));

	//Kill if outside window
	if (!checkInWindow()) kill(this);

}

void Projectile::damage(LivingEntity* _e)
{
	if (_e->getHealth() > 0)
	{
		_e->setHealth(_e->getHealth() - getDamage());
		kill(this);
	}
}

//Get Damage -- Different damage for each projectile type
float Bullet::getDamage() const
{
	return 1;
}

float Rocket::getDamage() const
{
	return 3;
}