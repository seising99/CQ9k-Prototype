#include "Projectile.h"
#include "TextureMap.h"
#include "Game.h"

//Projectile Constructor -- given position and velocity, projectile is constructed with appropriate texture
Projectile::Projectile(sf::Vector2f _pos, sf::Vector2f _vel)
{

	setTexture();
	sProjectile.setOrigin(sProjectile.getTextureRect().width / 2, sProjectile.getTextureRect().height / 2);

	pos = _pos;
	vel = _vel;

	sProjectile.setPosition(pos);

}

//Set Texture -- Defined functions for projectile types
void Bullet::setTexture()
{
	sProjectile.setTexture(TEXTURES("bullet"));
}

void Rocket::setTexture()
{
	sProjectile.setTexture(TEXTURES("bullet"));
	sProjectile.setColor(sf::Color::Red);
}

//Draw -- A projectile draws itself to the game window
void Projectile::Draw()
{
	WINDOW.draw(sProjectile);
}

//Getters and Setters
sf::Vector2f Projectile::getVelocity() const
{
	return vel;
}

sf::Vector2f Projectile::getPos() const
{
	return pos;
}

void Projectile::setVelocity(sf::Vector2f _vel)
{
	vel = _vel;
}

void Projectile::setPosition(sf::Vector2f _pos)
{
	pos = _pos;
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