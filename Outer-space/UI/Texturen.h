#pragma once

#include <SFML\Graphics.hpp>

class Texturen : sf::Sprite
{
public:

	enum class figures { PLAYERONE, PLAYERTWO, ENEMY };

	void changeFigures();

	Texturen();
	~Texturen();

};
