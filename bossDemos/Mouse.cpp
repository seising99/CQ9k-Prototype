#include "Mouse.h"
#include "Game.h"
#include "TextureMap.h"

Mouse::Mouse() : LivingEntity(TEXTURES("mouse"))
{

	canFire = true;
	rocketCount = 0;
	cooldownTime = 0;

	setHealth(100);

	setRotation(-30);
	setScale(sf::Vector2f(SCALE_X, SCALE_Y));

	setPriority(127);

}

Mouse::~Mouse() {}

void Mouse::fireBullet()
{

	sf::Vector2f pos = this->getPosition();
	sf::Vector2f vel = sf::Vector2f(cos((getRotation() - 90) * (float)3.1415926 / 180) * BULLET_SPEED, sin((getRotation() - 90) * (float)3.1415926 / 180) * BULLET_SPEED);

	Bullet* newBullet = new Bullet(pos, vel, getRotation());
	projectiles.push_back(newBullet);

}

void Mouse::fireRocket()
{

	sf::Vector2f pos = this->getPosition();
	sf::Vector2f vel = sf::Vector2f(cos((getRotation() - 90) * (float)3.1415926 / 180) * BULLET_SPEED, sin((getRotation() - 90) * (float)3.1415926 / 180) * BULLET_SPEED);

	Rocket* newBullet = new Rocket(pos, vel, getRotation());
	projectiles.push_back(newBullet);

}

void Mouse::damage(LivingEntity* _e)
{
	_e->setHealth(_e->getHealth() - 5);
}

std::vector<Projectile*> Mouse::getProjectiles()
{
	return projectiles;
}

void Mouse::update()
{

	setPosition(sf::Vector2f((float)sf::Mouse::getPosition(WINDOW).x, (float)sf::Mouse::getPosition(WINDOW).y));

}

void Mouse::inputHandler()
{

	//Rotating M.O.U.S.E. Angle
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
		setRotation(getRotation() - SLOW_ROT * DT);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
		setRotation(getRotation() + SLOW_ROT * DT);
		
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		setRotation(getRotation() - FAST_ROT * DT);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		setRotation(getRotation() + FAST_ROT * DT);

	//Fire Projectiles
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && canFire && checkInWindow())
	{
		canFire = false;
		fireBullet();
		cooldownClock.restart();
		cooldownTime = COOLDOWN_LEFT;
	}

	if (sf::Mouse::isButtonPressed(sf::Mouse::Right) && canFire && checkInWindow())
	{
		canFire = false;
		fireRocket();
		cooldownClock.restart();
		cooldownTime = COOLDOWN_RIGHT;
	}

	//Projectile Cooldown
	if (cooldownClock.getElapsedTime().asSeconds() > cooldownTime)
	{
		cooldownClock.restart();
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