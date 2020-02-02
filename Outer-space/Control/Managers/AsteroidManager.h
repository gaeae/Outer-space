#pragma once

#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>
#include <list>

#include "..\..\Models\Asteroid.h"

class AsteroidManager
{
public:
	AsteroidManager();
	~AsteroidManager();

	void insert(Asteroid *asteroid);

	void checkAsteroid();
	void spawn	(float spawntime);
	void update	(float frmtime);
	void handle	();
	void render	(sf::RenderWindow *rw);

	std::list<Asteroid*> *getList() { return &list_; };

private:
	sf::Clock *pClock;
	sf::SoundBuffer soundBuffer;
	sf::Sound soundExplosion;

	std::list<Asteroid*> list_;

	int		velocity_;
	int		rotation_;
	int		xpos_;
	int		ypos_;
	double	scaleFactor_;

	const float SPAWNTIME_ = 0.5;
};
