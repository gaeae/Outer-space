#include "AsteroidManager.h"

AsteroidManager::AsteroidManager()
{
	pClock = new sf::Clock();
	pClock->restart();

	//TODO von Music erben
	if (!soundBuffer.loadFromFile("explosion.wav"))
		std::cout << "Musik konnte nicht gelesen werden" << std::endl;

	soundExplosion.setBuffer(soundBuffer);
	soundExplosion.setVolume(50);

	velocity_ = 0;
	rotation_ = 0;
	xpos_ = 0;
	ypos_ = 0;
	scaleFactor_ = 0;
}

AsteroidManager::~AsteroidManager()
{
	delete pClock;

	pClock = nullptr;

	for (auto it : list_)
	{
		delete it;
		it = nullptr;
	}
	list_.clear();
}

void AsteroidManager::insert(Asteroid * asteroid)
{
	list_.push_back(asteroid);
}

void AsteroidManager::checkAsteroid()
{
	for (auto it = list_.begin(); it != list_.end();)
	{
		if ((*it)->getSprite().getPosition().y > 700)
		{
			delete (*it);
			(*it) = nullptr;
			it = list_.erase(it);
		}

		if (!(*it)->getIsAlive())
		{
			soundExplosion.play();
			//TODO : hier Explosionsliste anlegen?
			delete (*it);
			(*it) = nullptr;
			it = list_.erase(it);
		}
		else
		{
			it++;
		}
	}
}

void AsteroidManager::spawn(float time)
{
	if (pClock->getElapsedTime().asSeconds() > time)
	{
		velocity_ = rand() % 150 + 50;
		rotation_ = rand() % 100 + 20;
		xpos_ = rand() % 780 + 20;
		ypos_ = rand() % 200 - 200;
		scaleFactor_ = (rand() % 10 + 3.0) / 20.f;

		Asteroid *pAsteroid = new Asteroid("asteroid_new.png", sf::Vector2f((float)xpos_, (float)ypos_), sf::Vector2f((float)scaleFactor_, (float)scaleFactor_), (float)velocity_, (float)rotation_);

		list_.push_back(pAsteroid);

		pClock->restart();
	}
}

void AsteroidManager::update(float frmtime)
{
	spawn(SPAWNTIME_);

	checkAsteroid();

	// alternative to going throug the list with if-codition
	for (auto it : list_)
	{
		it->update(frmtime);
	}
}

void AsteroidManager::handle()
{
	for (auto it : list_)
	{
		it->handle();
	}
}

void AsteroidManager::render(sf::RenderWindow * rw)
{
	for (auto it : list_)
	{
		it->render(rw);
	}
}
