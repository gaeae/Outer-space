#pragma once

#include "..\..\Main\Framework.h"

class Framework;

class StateGame
{
public:

	virtual void HandleEvents	(Framework *game)		= 0;
	virtual void Update			(Framework *game)		= 0;
	virtual void Render			(sf::RenderWindow *rw)	= 0;

private:

};
