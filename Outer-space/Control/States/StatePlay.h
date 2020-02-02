#pragma once

#include <memory>
#include <random>

#include "..\..\Models\Player.h"
#include "..\..\Models\Asteroid.h"
#include "..\Managers\AsteroidManager.h"
#include "..\..\UI\Animation\CollisionSystem.h"
#include "..\..\Models\Enemy.h"

#include "..\..\Main\Framework.h"

class StatePlay : public StateGame
{
public:

	StatePlay(sf::RenderWindow *rw);
	~StatePlay();

	void Update			(Framework *game)		override;
	void HandleEvents	(Framework *game)		override;
	void Render			(sf::RenderWindow *rw)	override;


private:

	//std::unique_ptr<Player> uniquePlayer;
	//std::unique_ptr<Weapon> weaponSlot;
	//std::unique_ptr<HUD> m_PlayerHUD;
	//std::unique_ptr<std::vector<Ammo>> shotsVector;

	std::unique_ptr<Enemy> uniqueEnemy;

	Player			*pPlayer;
	AsteroidManager *pManagerAsteroid;
	CollisionSystem *pCollisionSystem;

	sf::Clock *pFrameClock;

	sf::Texture *pMouseTexture;
	sf::Texture textureEnemy;
	sf::Sprite	*pMouseSprite;
	//sf::Sprite spriteEnemy;

	float frameTime_;
	float elapsedTime_;

	int i;
};