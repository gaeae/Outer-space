#include <SFML\Graphics.hpp>
#include <iostream>
#include <stdio.h>

#include "Framework.h"

int main()
{
	Framework game;
	game.changeState(Framework::gameStates::MAINMENU);
	
	while (game.getIsRunning())
	{
		game.run();
	}
	return 0;
}