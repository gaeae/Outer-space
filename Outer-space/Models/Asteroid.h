#pragma once
#include <iostream>
#include <SFML\Graphics.hpp>

class Asteroid
{
public:
	Asteroid(std::string texturePath_, sf::Vector2f position, sf::Vector2f scaleFactor, float velocity, float rotation);
	~Asteroid();

	void update(float frmtime);
	void render(sf::RenderWindow *rw);
	void handle();

	void setLife		(float live);
	void setIsAlive		(bool isAlive);
	void setIsTarget	(bool isTarget);

	const sf::Sprite &getSprite() { return *pSpriteAsteroid; };

	const float getLife()		{ return life_; };
	const bool	getIsAlive()	{ return isAlive_; };
	const bool	getIsTarget()	{ return isTarget_; };

private:
	sf::Texture *pTextureAsteroid;
	sf::Texture *pTextureTarget;
	sf::Texture *pTextureLifeAsteroid;
	sf::Texture *pTextureExplosion;

	sf::Sprite	*pSpriteAsteroid;
	sf::Sprite	*pSpriteLifeAsteroid;

	float velocity_;
	float rotation_;

	float step_;
	float life_;
	bool isAlive_;
	bool isTarget_;
};
