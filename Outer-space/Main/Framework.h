#pragma once
#include <iostream>
#include <map>
#include <tuple>
#include <list>
#include <string>
#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>

#include "..\Control\States\StateGame.h"
#include "..\Control\States\StateMenu.h"

class StateGame;

class Framework {
public:

	enum class gameStates {MAINMENU, PLAY, OPTION};

	/*
		Singleton
	*/
	static Framework& get_instance()
	{
		static Framework instance;
		return instance;
	}
	Framework();
	Framework			(const Framework&) = delete;
	Framework& operator=(const Framework&) = delete;
	~Framework();

	sf::RenderWindow *pRenderWindow;

	void run();
	void changeState(gameStates newState);

	template <typename T> void saveValues(std::string typ, T values);

	//SETTER
	void setRun(bool isRunning);

	//GETTER
	bool getIsRunning() { return run_; };

private:

	sf::Event	*pMainEvent;
	sf::Clock	*pClock;
	sf::Texture *pBackgroundTexture;
	sf::Sprite	*pBackgroundSprite;
	sf::Time	*pTime;
	sf::Font	*pFont;
	sf::Text	textFPS_;
 
	void update(float frametime);
	void handleEvents();
	void quit();
	void render();
	void fps();
	void calculateFrameTime();

	bool run_;
	float frameTime_;

	std::unique_ptr<StateGame> pCurrendState_;
	
};
