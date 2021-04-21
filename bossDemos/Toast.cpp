#include "Toast.h"
#include "TextureMap.h"
#include "Game.h"
#include "VectorMath.h"
#include "EntityManager.h"

Toast::Toast() : Enemy(TEXTURES("toaster"))
{
	
	frame = 0;

	sf::Vector2f pos(0.0f, 0.0f);

	getSprite()->setTextureRect(sf::IntRect(0, 0, 128, 128));
	getSprite()->setOrigin(64, 64);

	int edge = rand() % 3;

	bool validSpot = false;
	int attempts = 0;

	while (!validSpot)
	{
		attempts++;
		validSpot = true;

		if (edge > 1)
		{
			pos.x += WINDOW.getSize().x;
			pos.y += rand() % WINDOW.getSize().y;
		}
		else
		{
			pos.x += rand() % WINDOW.getSize().x;
			pos.y += 0.0f;
		}

		setPosition(pos);

		for(unsigned int i = 0; i < toasts.size(); i++)
			if (checkCollision(*this, *toasts[i], false))
			{
				validSpot = false;
			}

		if (attempts >= 3)
			validSpot = true;


	}


	setVelocity(sf::Vector2f(-1.0f * DT * 400, 1.0f * DT * 400));

	setHealth(5.0f);

	toasts.push_back(this);

}

Toast::~Toast()
{
	auto it = std::find(toasts.begin(), toasts.end(), this);
	toasts.erase(it);
}

void Toast::animate()
{

	getSprite()->setTextureRect(sf::IntRect(128 * frame, 0, 128, 128));
	count++;

	if (count >= 3)
	{
		frame++;
		count = 0;
	}

	if (frame > 13)
		frame = 0;
}

void Toast::update()
{

	animate();

	setPosition(getPosition() + getVelocity());

	if (!checkInWindow()) setHealth(0);
	if (getHealth() <= 0) delete this;

}

float Toast::getDamage()
{
	return 5.0f;
}