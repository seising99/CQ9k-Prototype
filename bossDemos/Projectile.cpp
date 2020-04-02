#include "Projectile.h"
#include "TextureMap.h"
#include "Game.h"

Projectile::Projectile(sf::Vector2f _pos, sf::Vector2f _vel, const sf::Texture& txt) : Entity(txt) {}

Bullet::Bullet(sf::Vector2f _pos, sf::Vector2f _vel) : Projectile(_pos, _vel, TEXTURES("bullet")) {}

Rocket::Rocket(sf::Vector2f _pos, sf::Vector2f _vel) : Projectile(_pos, _vel, TEXTURES("bullet")) {}

//Update Position -- Calculate new position for projectile based on current position and velocity, and update model (sprite)
void Projectile::update()
{

	setPosition(getPosition() + (getVelocity() * (DT * SPEED)));

	//Delete if outside window
	if (!checkInWindow()) delete this;

}

//Get Damage -- Different damage for each projectile type
int Bullet::getDamage()
{
	return 1;
}

int Rocket::getDamage()
{
	return 3;
}