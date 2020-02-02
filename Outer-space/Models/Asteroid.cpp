#include "Asteroid.h"
#include <SFML\Graphics.hpp>

Asteroid::Asteroid(std::string texturePath_, sf::Vector2f position, sf::Vector2f scaleFactor, float velocity, float rotation)
{
	// Asteroid Graphic
	sf::Image subImage;
	subImage.loadFromFile(texturePath_);
	subImage.createMaskFromColor(sf::Color::White);

	pTextureAsteroid = new sf::Texture;
	pTextureAsteroid->loadFromImage(subImage);

	pSpriteAsteroid = new sf::Sprite;
	pSpriteAsteroid->setTexture(*pTextureAsteroid);
	pSpriteAsteroid->setScale(scaleFactor);
	pSpriteAsteroid->setPosition(position);
	pSpriteAsteroid->setOrigin(pTextureAsteroid->getSize().x / 2, pTextureAsteroid->getSize().y / 2);

	// Asteroid Focus Graphic
	pTextureTarget = new sf::Texture;
	pTextureTarget->loadFromFile("asteroid_new_target.png");

	// Asteroid Health Graphic
	pTextureLifeAsteroid = new sf::Texture;
	pTextureLifeAsteroid->loadFromFile("health.png");

	pSpriteLifeAsteroid = new sf::Sprite;
	pSpriteLifeAsteroid->setTexture(*pTextureLifeAsteroid);
	pSpriteLifeAsteroid->setScale(scaleFactor);
	pSpriteLifeAsteroid->setOrigin(pTextureAsteroid->getSize().x / 2, pTextureAsteroid->getSize().y / 2);
	//pSpriteLifeAsteroid->setPosition(position); //funktioniert nicht, da pSpriteLifeAsteroid nicht bewegt wird (s. update)

	// Explosion Graphic
	sf::Image imageExplosion;
	imageExplosion.loadFromFile("explosion2.png");
	imageExplosion.createMaskFromColor(sf::Color::White);

	pTextureExplosion = new sf::Texture;
	pTextureExplosion->loadFromImage(imageExplosion);


	velocity_ = velocity;
	rotation_ = rotation;

	setLife(100);
	setIsAlive(true);
	setIsTarget(false);

	step_ = pTextureLifeAsteroid->getSize().x / getLife();
}

Asteroid::~Asteroid()
{
	delete pTextureAsteroid;
	delete pSpriteAsteroid;
	delete pTextureTarget;
	delete pTextureLifeAsteroid;
	delete pSpriteLifeAsteroid;
	delete pTextureExplosion;

	pTextureAsteroid		= nullptr;
	pSpriteAsteroid			= nullptr;
	pTextureTarget			= nullptr;
	pTextureLifeAsteroid	= nullptr;
	pSpriteLifeAsteroid		= nullptr;
	pTextureExplosion		= nullptr;
}

void Asteroid::update(float frmtime)
{
	pSpriteAsteroid->rotate(rotation_ * frmtime);
	pSpriteAsteroid->move(0, velocity_ * frmtime);

	if (this->getIsTarget())
		pSpriteAsteroid->setTexture(*pTextureTarget);
	else
		pSpriteAsteroid->setTexture(*pTextureAsteroid);
	if (!this->getIsAlive())
	{
		pSpriteAsteroid->setTexture(*pTextureExplosion);
		
	}
		

	pSpriteLifeAsteroid->setPosition(pSpriteAsteroid->getPosition().x, pSpriteAsteroid->getPosition().y);
	pSpriteLifeAsteroid->setTextureRect(sf::IntRect(0, 0, (step_*getLife()), pTextureLifeAsteroid->getSize().y));
}

void Asteroid::render(sf::RenderWindow *rw)
{
	rw->draw(*pSpriteAsteroid);

	if (this->getIsTarget())
		rw->draw(*pSpriteLifeAsteroid);
}

void Asteroid::handle()
{
}

void Asteroid::setLife(float live)
{
	life_ = live;
}

void Asteroid::setIsAlive(bool isAlive)
{
	isAlive_ = isAlive;
}

void Asteroid::setIsTarget(bool isTarget)
{
	isTarget_ = isTarget;
}
