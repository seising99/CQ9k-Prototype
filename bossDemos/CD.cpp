#include "CD.h"
#include "TextureMap.h"
#include "Game.h"
#include "VectorMath.h"
#include "EntityManager.h"

CD::CD() : Enemy(TEXTURES("cd"))
{

	frame = 0;

	sf::Vector2f pos(0.0f, 0.0f);

	getSprite()->setTextureRect(sf::IntRect(0, 0, 32, 32));
	getSprite()->setOrigin(16, 16);
	getSprite()->setScale(2.5f, 2.5f);

	bool edge = rand() % 2;

	if (edge)
	{
		pos.x += WINDOW.getSize().x * (rand() % 2);
		pos.y += rand() % WINDOW.getSize().y;
	}
	else
	{
		pos.x += rand() % WINDOW.getSize().x;
		pos.y += WINDOW.getSize().y * (rand() % 2);
	}

	setPosition(pos);

	sf::Vector2f towardsMouse = VectorMath::Normalize(sf::Vector2f(sf::Mouse::getPosition(WINDOW).x - this->getPosition().x, sf::Mouse::getPosition(WINDOW).y - this->getPosition().y));
	setVelocity(sf::Vector2f(towardsMouse.x * DT * 900, towardsMouse.y * DT * 900));

	setHealth(5.0f);

	disks.push_back(this);

}

CD::~CD()
{
	auto it = std::find(disks.begin(), disks.end(), this);
	disks.erase(it);
}

void CD::animate()
{

	getSprite()->setTextureRect(sf::IntRect(32 * frame, 0, 32, 32));
	count++;

	if (count >= 2)
	{
		frame++;
		count = 0;
	}

	if (frame > 3)
		frame = 0;
}

void CD::update()
{

	animate();

	setPosition(getPosition() + getVelocity());

	if (!checkInWindow()) setHealth(0);
	if (getHealth() <= 0) delete this;

}

float CD::getDamage()
{
	return 5.0f;
}