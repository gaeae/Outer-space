#pragma once

#include "..\UI\Texturen.h"

class Enemy : public sf::Sprite
{
public:

	Enemy(sf::Texture &texture);
	~Enemy();

	void update(float elapsedTime);
	void render(sf::RenderWindow *rw);

	//SETTER
	void setSpeed	(float speed);
	void setName	(std::string name);
	void setIsAlive	(bool isAlive);
	void setHealth	(float health);
	void setDamage	(float damage);

	//GETTER
	float getSpeed()		{ return speed_; };
	float getHealth()		{ return health_; };
	float getDamage()		{ return damage_; };
	bool getIsAlive()		{ return isAlive_; };
	std::string getName()	{ return name_; };


private:

	float speed_;
	float health_;
	float damage_;
	bool isAlive_;
	std::string name_;
};
