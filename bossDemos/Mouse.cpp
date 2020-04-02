#include "Mouse.h"
#include "Game.h"
#include "TextureMap.h"
#include <iostream>

Mouse::Mouse() : Entity(TEXTURES("mouse"), .75f, .75f)
{

	canFire = true;
	rocketCount = 0;

	setHealth(100);
	setRotation(-30);

}

Mouse::~Mouse() {}

void Mouse::fireBullet()
{

	sf::Vector2f pos = this->getPosition();
	sf::Vector2f vel = sf::Vector2f(cos((getRotation() - 90) * (float)3.1415926 / 180) * 20, sin((getRotation() - 90) * (float)3.1415926 / 180) * 20);

	Bullet* newBullet = new Bullet(pos, vel);
	projectiles.push_back(newBullet);

}

void Mouse::fireRocket()
{

	sf::Vector2f pos = this->getPosition();
	sf::Vector2f vel = sf::Vector2f(cos((getRotation() - 90) * (float)3.1415926 / 180) * 20, sin((getRotation() - 90) * (float)3.1415926 / 180) * 20);

	Rocket* newBullet = new Rocket(pos, vel);
	projectiles.push_back(newBullet);

}

std::vector<Projectile*> Mouse::getProjectiles()
{
	return projectiles;
}

void Mouse::update()
{

	setPosition(sf::Vector2f((float)sf::Mouse::getPosition(WINDOW).x, (float)sf::Mouse::getPosition(WINDOW).y));

	for (auto&& i : projectiles)
		i->update();

}

void Mouse::inputHandler()
{

	//Rotating M.O.U.S.E. Angle
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
		setRotation(getRotation() -200 * DT);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
		setRotation(getRotation() + 200 * DT);
		
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		setRotation(getRotation() - 400 * DT);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		setRotation(getRotation() + 400 * DT);

	//Fire Projectiles
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && canFire)
	{
		canFire = false;
		std::cout << "FIRED" << std::endl;
		fireBullet();
		cooldown.restart();
	}

	//Projectile Cooldown
	if (cooldown.getElapsedTime().asSeconds() > 0.5)
	{
		cooldown.restart();
		canFire = true;
	}

}

int Mouse::getRocketCount() const
{
	return rocketCount;
}

void Mouse::setRocketCount(int newCount)
{
	rocketCount = newCount;
}