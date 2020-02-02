#pragma once

#include <functional>

#include <SFML\Graphics.hpp>
#include "..\..\Main\Framework.h"


class StateOption : public StateGame , public Music
{
public:

	//Singleton
	//StateOption(const StateOption&) = delete;
	//StateOption& operator=(const StateOption&) = delete;
	//static StateOption& get_instance() 
	//{
	//	static StateOption instance;
	//	return instance;
	//}
	//StateOption();

	StateOption(sf::RenderWindow *rw);
	~StateOption();

	void Update			(Framework *game)		override;
	void HandleEvents	(Framework *game)		override;
	void Render			(sf::RenderWindow *rw)	override;

private:

	void toggle(bool key, bool variable);

	std::shared_ptr<Button> pBackButton_;
	std::shared_ptr<Button> pMusicButton_;

	bool isBackClicked_;
	bool isMusicButtonClicked_;
	bool musicToogle_;
};