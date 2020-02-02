#pragma once

#include "SFML\Audio.hpp"

class Sound : sf::Sound
{
public:

	Sound();
	~Sound();

	void update();
	void handle();

private:
};
