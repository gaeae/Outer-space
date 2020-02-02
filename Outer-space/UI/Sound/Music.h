#pragma once

#include <string>

#include <SFML\Audio.hpp>

class Music
{
public:

	void loadMusic(std::string musicName);
	void playMusic();
	void volume(bool onOff);

protected:

	bool musicBotton;

private:

	sf::SoundBuffer soundBuffer_;
	sf::Sound		sound_;
};