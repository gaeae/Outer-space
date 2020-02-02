#include "Framework.h"
#include "LoadResources.h"
#include "..\Control\States\StatePlay.h"
#include "..\Control\States\StateOption.h"

#include <sstream>
#include <string>s
#include <iomanip>
#include <utility>
#include <fstream>

template<typename T>
inline void Framework::saveValues(std::string typ, T values)
{
	typedef std::map<std::string, T> saveMap;
	saveMap theMap;
	
	typedef std::map<std::string, T>::iterator it_type;
	it_type iterator;

	std::pair<std::string, T> pair;
	pair = std::make_pair(typ, values);
	theMap.insert(pair);

	for (auto& x : theMap)
	{
		std::fstream testDatei;
		testDatei.open("saveValues.txt", std::fstream::app);
		if (testDatei.is_open())
		{
			testDatei << x.first << ": " << x.second << std::endl;
			testDatei.close();
			std::cout << "Textdatei beschrieben!" << std::endl;
		}
		else
		{
			std::cout << "Fehler beim öffnen der Datei";
		}
	}

	for(iterator = theMap.begin(); iterator !=theMap.end(); iterator++ )
	{
		std::cout << "Iterator 1: " << iterator->first << " --- Iterator 2: " << iterator->second << std::endl;
	}
}

Framework::Framework()
{
	pRenderWindow = new sf::RenderWindow;
	pRenderWindow->create(sf::VideoMode(800, 600, 32), "Name", sf::Style::Close);
	pRenderWindow->setFramerateLimit(60);

	pMainEvent	= new sf::Event;
	pClock		= new sf::Clock;
	pClock->restart();
	pTime		= new sf::Time;
	pFont		= new sf::Font;
    std::string font = LoadResources::GetFontArial();
	pFont->loadFromFile(font);
	
	textFPS_.setFont(*pFont);
	textFPS_.setCharacterSize(20);
	textFPS_.setString("FPS: ");
	textFPS_.setFillColor(sf::Color::Yellow);
	textFPS_.setPosition(720, 0);

	run_ = true;
	frameTime_ = 0;

	pBackgroundTexture = new sf::Texture;
	pBackgroundTexture->loadFromFile("..\\Resources\\Images\\background.jpg");

	pBackgroundSprite = new sf::Sprite;
	pBackgroundSprite->setTexture(*pBackgroundTexture);

	std::shared_ptr<StateOption> pSharedOption;
	pSharedOption = std::make_shared<StateOption>(pRenderWindow);
}

Framework::~Framework()
{
	delete pRenderWindow;
	delete pMainEvent;
	delete pClock;
	delete pBackgroundTexture;
	delete pBackgroundSprite;
	delete pTime;

	pRenderWindow		= nullptr;
	pMainEvent			= nullptr;
	pClock				= nullptr;
	pBackgroundTexture	= nullptr;
	pBackgroundSprite	= nullptr;
	pTime				= nullptr;
}

void Framework::run()
{
	while (run_)
	{
		calculateFrameTime();
		update(frameTime_);
		handleEvents();
		render();
		quit();
	}
}

void Framework::changeState(gameStates newState)
{
	switch (newState)
	{
	case(gameStates::MAINMENU):
		pCurrendState_ = std::make_unique<StateMenu>(pRenderWindow);
		pRenderWindow->setTitle("Menu");
		break;

	case(gameStates::PLAY):
		pCurrendState_ = std::make_unique<StatePlay>(pRenderWindow);
		pRenderWindow->setTitle("Play");
		break;

	case(gameStates::OPTION):
		pCurrendState_ = std::make_unique<StateOption>(pRenderWindow);
		pRenderWindow->setTitle("Option");

		saveValues("bool", true);
		saveValues("string", "test");
		saveValues("int", 3);
		break;

	default:
		std::cout << " Kein Gamestate" << std::endl;
		break;
	}
}

void Framework::setRun(bool isRunning)
{
	run_ = isRunning;
}

void Framework::quit()
{
	if (!run_)
		pRenderWindow->close();
}

void Framework::update(float frmtime)
{
	pCurrendState_->Update(this);
}

void Framework::handleEvents()
{
	while (pRenderWindow->pollEvent(*pMainEvent))
	{
		if (pMainEvent->type == sf::Event::Closed)
			run_ = false;

		pCurrendState_->HandleEvents(this);
	}
}

void Framework::render()
{
	pRenderWindow->draw(*pBackgroundSprite);
	pCurrendState_->Render(pRenderWindow);
	pRenderWindow->draw(textFPS_);

	//never forget!
	pRenderWindow->display();
}

void Framework::fps()
{
	*pTime = pClock->getElapsedTime();
	std::stringstream ss;
	ss << round(1 / pTime->asSeconds());
	textFPS_.setString("FPS: " + ss.str());
}

void Framework::calculateFrameTime()
{
	frameTime_ = pClock->getElapsedTime().asSeconds();

	fps();

	pClock->restart();
}
