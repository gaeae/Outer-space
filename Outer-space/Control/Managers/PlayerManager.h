#pragma once

#include <SFML\Graphics.hpp>
#include <iostream>
#include "..\..\Models\Player.h"

class PlayerManager
{
public:
	PlayerManager();
	~PlayerManager();

	void update(float frmtime);
	void handle();
	void render(sf::RenderWindow *rw);

private:
};