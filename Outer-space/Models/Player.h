#pragma once
#include <iostream>
#include <SFML\Graphics.hpp>

#include "Weapon.h"
#include "Shot.h"
#include "..\Main\Framework.h"


class Player
{
public:
	//! \brief Constructor of class player
	//! loading texture of the player
	//! \param string 
	//! \param vector position which descriptes the starting postion of player
	Player();
	~Player();
	//std::string texturePath, sf::Vector2f position

	//! \brief update window e.g. moves or something
	//! \param float frmTime_ 
	void update(float frmTime_);

	// TODO comment
	void render(sf::RenderWindow *rw);
	//TODO comment
	void handle(Framework *framework);

	void setLife	(float life);
	void setIsAlive	(bool isAlive);
	void setPoints	(float points);
	void setShield	(float shield);

	const sf::Sprite	&getSprite()		{ return *pPlayerSprite; };
	const sf::Vector2f	getMousePosition()	{ return mousePosition_; };
	std::list<Shot*>	*getShotList()		{ return weapon->getShotList(); };


	const float getLife()		{ return life_; };
	const bool	getIsAlive()	{ return isAlive_; };
	const float getPoints()		{ return points_; };
	const float	getShield()		{ return shield_; };

private:

	Weapon *weapon;
	
	//! \brief Pointer to include the image of player 
	sf::Texture	*pPlayerTexture;
	//! \brief Pointer to render the image of player
	sf::Sprite	*pPlayerSprite;

	sf::Texture *pShieldTexture;
	sf::Sprite	*pShieldSprite;
	sf::Font	*pFont;

	sf::Vector2f mousePosition_;

	sf::Text	textPunkte_;
	sf::Text	textLife_;
	sf::Text	textShield_;


	float	life_;
	bool	isAlive_;
	float	points_;
	float	shield_;
	float	step_;
};
