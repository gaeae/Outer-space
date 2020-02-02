#pragma once

#include <iostream>
#include <SFML\Graphics.hpp>
#include <list>

#include "Collision.h"
#include "..\..\Models\Player.h"
#include "..\..\Models\Asteroid.h"

class CollisionSystem
{
public:
	CollisionSystem(sf::Sprite *mouse, Player *player, std::list<Asteroid*> *list);
	~CollisionSystem();

	void update(float frametime);
private:
	//TODO delete?
	Player					*pPlayer;
	sf::Sprite				*pMouse;
	std::list<Asteroid*>	*pList;
};
