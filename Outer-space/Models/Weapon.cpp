#include "Weapon.h"

#include <iostream>

Weapon::Weapon()
{
	sf::Image subImage;
	subImage.loadFromFile("shot.png");
	subImage.createMaskFromColor(sf::Color::White);

	pTextureShot = new sf::Texture;
	pTextureShot->loadFromImage(subImage);

	pClock = new sf::Clock;
	pClock->restart();

	cooldown_ = 0.075f;
	lock_ = true;

	positionPlayer_		= sf::Vector2f(0.f, 0.f);
	positionCorrection_ = sf::Vector2f(0.f, -50.f);
}

Weapon::~Weapon()
{
	delete pClock;
	delete pTextureShot;

	pClock			= nullptr;
	pTextureShot	= nullptr;
}

void Weapon::update(sf::Vector2f position, sf::Vector2f player, float frametime)
{
	positionPlayer_ = player; //+ positionCorrection_;

	if (!lock_)
		if (pClock->getElapsedTime().asSeconds() > cooldown_)
			lock_ = true;

	///////////////////////////////////////////////////////////////////////////////////
	//Richtung berechnen
	targetDirection_ = position - player;
	const float lenght = sqrt(pow(targetDirection_.x, 2) + pow(targetDirection_.y, 2));
	targetDirection_ = targetDirection_ /= lenght;
	///////////////////////////////////////////////////////////////////////////////////

	for (auto it = list_.begin(); it != list_.end();)
	{
		if (((*it)->getIsAlive() == false))
		{
			delete (*it);
			(*it) = nullptr;

			it = list_.erase(it);
		}
		else
		{
			(*it)->update(frametime);
			it++;
		}
	}
}

void Weapon::render(sf::RenderWindow* rw)
{
	for (auto it : list_)
	{
		rw->draw(it->getSprite());
		//it->render(rw);
	}
}

void Weapon::fire()
{
	if (lock_)
	{
		Shot *s = new Shot(targetDirection_,positionPlayer_, pTextureShot);
		
		list_.push_back(s);

		lock_ = false; 

		pClock->restart();
	}
}
