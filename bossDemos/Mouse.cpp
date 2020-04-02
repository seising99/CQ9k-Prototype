#include "Mouse.h"
#include "Game.h"
#include "TextureMap.h"

Mouse::Mouse()
{

	sMouse.setTexture(TEXTURES("mouse"));
	sMouse.setOrigin(sMouse.getTextureRect().width / 2, sMouse.getTextureRect().height / 2);
	sMouse.setScale(sf::Vector2f(0.75f, 0.75f));

	angle = -30;

	rocketCount = 0;

}

Mouse::~Mouse() {}

void Mouse::fireBullet()
{

	sf::Vector2f pos = this->getPosition();
	sf::Vector2f vel = sf::Vector2f(cos((angle - 90) * (float)3.1415926 / 180) * 20, sin((angle - 90) * (float)3.1415926 / 180) * 20);

	Bullet* newBullet = new Bullet(pos, vel);
	projectiles.push_back(newBullet);

}

void Mouse::fireRocket()
{

	sf::Vector2f pos = this->getPosition();
	sf::Vector2f vel = sf::Vector2f(cos((this->getAngle() - 90) * (float)3.1415926 / 180) * 20, sin((this->getAngle() - 90) * (float)3.1415926 / 180) * 20);

	Bullet* newBullet = new Bullet(pos, vel);
	projectiles.push_back(newBullet);

}

sf::Vector2f Mouse::getPosition()
{
	return position;
}

std::vector<Projectile*> Mouse::getProjectiles()
{
	return projectiles;
}

void Mouse::updatePositions()
{

	position = sf::Vector2f((float)sf::Mouse::getPosition(WINDOW).x, (float)sf::Mouse::getPosition(WINDOW).y);

	sMouse.setPosition(position);
	sMouse.setRotation(angle);

	//Reset angle at 360
	if (angle > 360) angle = angle - 360;


}

void Mouse::inputHandler()
{

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
		angle -= 200 * DT;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
		angle += 200 * DT;
		
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		angle -= 400 * DT;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		angle += 400 * DT;

}

void Mouse::Draw()
{

	if (checkInWindow())
	{
		WINDOW.draw(sMouse);
	}

	//Draw mouse's projectiles
	for (auto&& p : projectiles)
		p->Draw();

}

bool Mouse::checkInWindow()
{

	sf::FloatRect currentView(WINDOW.getView().getCenter().x - WINDOW.getView().getSize().x / 2, WINDOW.getView().getCenter().y - WINDOW.getView().getSize().y / 2, WINDOW.getView().getSize().x, WINDOW.getView().getSize().y);

	if (currentView.contains(this->getPosition().x, this->getPosition().y)) return true;
	else return false;

}

int Mouse::getRocketCount() const
{
	return rocketCount;
}

void Mouse::setRocketCount(int newCount)
{
	rocketCount = newCount;
}

float Mouse::getAngle() const
{
	return angle;
}

void Mouse::setAngle(float newAngle)
{
	angle = newAngle;
}

sf::Sprite Mouse::getSprite()
{
	return sMouse;
}