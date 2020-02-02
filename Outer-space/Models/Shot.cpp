#include "Shot.h"

Shot::Shot(sf::Vector2f direction, sf::Vector2f position, sf::Texture* texture)
{
	pClock = new sf::Clock;
	pClock->restart();

	pSprite = new sf::Sprite;
	pSprite->setTexture(*texture);
	pSprite->setPosition(position);
	pSprite->setRotation(atan2(direction.y, direction.x) / 3.1415926 * 180);
	pSprite->setOrigin(texture->getSize().x/ 2, texture->getSize().y / 2);
	pSprite->setScale(1, 1);
	
	direction_ = direction;

	setIsAlive(true);
	speed_ = 700;
}

Shot::~Shot()
{
	delete pClock;
	delete pSprite;

	pClock	= nullptr;
	pSprite = nullptr;
}

void Shot::update(float frametime)
{
	pSprite->move(direction_ * (speed_*frametime));

	if (pClock->getElapsedTime().asSeconds() > 2.f)
		setIsAlive(false);
}

void Shot::render(sf::RenderWindow *rw)
{
	rw->draw(*pSprite);
}

void Shot::setIsAlive(bool isAlive)
{
	isAlive_ = isAlive;
}
