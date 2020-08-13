#include "Parasite.h"
#include "TextureMap.h"
#include "Game.h"
#include "VectorMath.h"
#include "EntityManager.h"

Parasite::Parasite() : Enemy(TEXTURES("parasite"))
{

	getSprite()->setScale(sf::Vector2f(1.5f, 1.5f));

	sf::Vector2f pos(0.0f, 0.0f);
	sf::Vector2f vel(0.0f, 0.0f);

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
	setHealth(5.0f);

	parasites.push_back(this);

}

Parasite::~Parasite()
{
	auto it = std::find(parasites.begin(), parasites.end(), this);
	parasites.erase(it);
}

void Parasite::update()
{

	sf::Vector2f accMouse = getAlign();
	sf::Vector2f accDist = getSeparation();
	
	//Normalize and adjust velocity vector
	sf::Vector2f newVel = VectorMath::Normalize((accMouse * ACC_WEIGHT) + (accDist * SEP_WEIGHT) + (getVelocity() * VEL_WEIGHT));

	//Adjust for deltaTime * a constant
	newVel.x *= DT_CONST * DT;
	newVel.y *= DT_CONST * DT;

	setVelocity(newVel);
	setPosition(getPosition() + getVelocity());

	if (getHealth() <= 0) delete this;

}

sf::Vector2f Parasite::getAlign()
{
	sf::Vector2f acc = VectorMath::Normalize(sf::Vector2f(sf::Mouse::getPosition(WINDOW).x - this->getPosition().x, sf::Mouse::getPosition(WINDOW).y - this->getPosition().y));
	return acc;
}

sf::Vector2f Parasite::getSeparation()
{

	sf::Vector2f sum(0, 0);

	for (Parasite* p : parasites)
	{

		if (p != this)
		{

			sf::Vector2f acc = this->getPosition() - p->getPosition();
			float dist = VectorMath::Length(acc);
			float safeDist = 74; // 5 pixel radius around each

			if (dist < safeDist)
			{

				acc = VectorMath::Normalize(acc);
				acc = acc *((safeDist - dist) / safeDist);
				sum += acc;

			}

		}

	}

	if (VectorMath::Length(sum) > 1)
		sum = VectorMath::Normalize(sum);

	return sum;

}

float Parasite::getDamage()
{
	return 5.0f;
}
