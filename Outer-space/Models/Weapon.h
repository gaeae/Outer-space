#pragma once
#include <SFML\Graphics.hpp>
#include <iostream>
#include <list>

#include "Shot.h"

class Weapon
{
public:

	Weapon();
	~Weapon();

	void update(sf::Vector2f position, sf::Vector2f player, float frametime);
	void render(sf::RenderWindow *sf);
	void fire();

	std::list<Shot*> *getShotList() {return &list_; };

private:

	sf::Clock			*pClock;
	sf::Vector2f		targetDirection_;
	sf::Vector2f		positionPlayer_;
	sf::Vector2f		positionCorrection_;
	sf::Texture			*pTextureShot;
	std::list<Shot*>	list_;

	bool lock_;
	float cooldown_;
};
