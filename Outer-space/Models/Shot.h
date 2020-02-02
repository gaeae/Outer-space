#pragma once
#include <SFML\Graphics.hpp>
#include <iostream>

class Shot
{
public:

	Shot(sf::Vector2f direction, sf::Vector2f position, sf::Texture *texture);
	~Shot();

	void update		(float frametime);
	void render		(sf::RenderWindow *rw);

	void setIsAlive	(bool isAlive);

	const bool getIsAlive()			{ return isAlive_; };
	const sf::Sprite &getSprite()	{ return *pSprite; };

private:

	sf::Clock		*pClock;
	sf::Sprite		*pSprite;
	
	sf::Vector2f	direction_;

	bool			isAlive_;
	float			speed_;
};