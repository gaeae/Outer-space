#include "CollisionSystem.h"


CollisionSystem::CollisionSystem(sf::Sprite * mouse, Player * player, std::list<Asteroid*>* list)
{
	pPlayer = player;
	pList	= list;
	pMouse	= mouse;
}

CollisionSystem::~CollisionSystem()
{
}

void CollisionSystem::update(float frametime)
{
	for (auto it : *pList)
	{
		for (auto it_list : *pPlayer->getShotList())
		{
			if (Collision::PixelPerfectTest(it_list->getSprite(), it->getSprite()))
			{
				it_list->setIsAlive(false);
				it->setLife(it->getLife() - 50); 
			}
		}

		if (Collision::PixelPerfectTest(pPlayer->getSprite(), it->getSprite()))
		{
			it->setLife(it->getLife() - 50 * frametime);

			if (pPlayer->getShield() > 0)
			{
				pPlayer->setShield(pPlayer->getShield() - 50 * frametime);
				
				if (pPlayer->getShield() < 0)
					pPlayer->setShield(0);
			}
				

			if (pPlayer->getShield() == 0 || pPlayer->getShield() < 0)
			{
				pPlayer->setLife(pPlayer->getLife() - 50 * frametime);

				if (pPlayer->getLife() < 0)
					pPlayer->setLife(0);
			}	
		}

		if (Collision::PixelPerfectTest(*pMouse, it->getSprite()))
		{
			it->setIsTarget(true);
		}
		else
		{
			it->setIsTarget(false);
		}

		if (it->getLife() == 0 || it->getLife() < 0)
		{
			it->setIsAlive(false);
		}

		if (it->getIsAlive() == false)
		{
			pPlayer->setPoints(pPlayer->getPoints()+10);
		}
	}
}
