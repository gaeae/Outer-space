#pragma once

#include <memory>

#include "..\..\UI\Button.h"
#include "StateGame.h"
#include "..\..\Main\Framework.h"
#include "..\..\UI\Sound\Music.h"


class StateMenu : public StateGame , public Music
{
public:

	StateMenu(sf::RenderWindow *rw);
	~StateMenu();

	void Update			(Framework *framework)	override;
	void HandleEvents	(Framework *framework)	override;
	void Render			(sf::RenderWindow *rw)	override;

private:

	std::shared_ptr<Button> pExitButton_;
	std::shared_ptr<Button> pPlayButton_;
	std::shared_ptr<Button> pOptionButton_;

	std::shared_ptr<Music> pMusicPlayer_;

	bool isClickedExit_;
	bool isClickedPlay_;
	bool isClickedOption_;

	void resetButton();

	sf::SoundBuffer soundbufferStart;
	sf::Sound		soundStart;

	sf::SoundBuffer soundbufferExit;
	sf::Sound		soundExit;
};