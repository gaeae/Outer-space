#pragma once

#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>
#include <string.h>

class GUI
{
public:

	// Pure-Virtual Funktion --> Abstrakte Klasse
	virtual bool Hover	(sf::RenderWindow *rw)	= 0;
	virtual bool Click	(sf::RenderWindow *rw)	= 0;
	virtual void Render	(sf::RenderWindow *rw)	= 0;

protected:

	bool hovered_;
	bool clicked_;
};