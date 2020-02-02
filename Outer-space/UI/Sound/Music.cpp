#include "Music.h"

#include <iostream>


void Music::loadMusic(std::string musicName)
{
	if (!soundBuffer_.loadFromFile(musicName))
	{
		std::cout << "ERROR: Couldnt load soundfile!" << std::endl;
	}
	sound_.setBuffer(soundBuffer_);
	sound_.setVolume(50);
	sound_.setLoop(false);
}

void Music::playMusic()
{
	sound_.play();
}

void Music::volume(bool volumeOff)
{
	if (volumeOff)
	{
		sound_.setVolume(0);
	}
	else if(!volumeOff)
	{
		sound_.setVolume(50);
	}
}
