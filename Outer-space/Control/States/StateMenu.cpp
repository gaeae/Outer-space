#include "StateMenu.h"

#include <Windows.h>

StateMenu::StateMenu(sf::RenderWindow *rw)
{
	pExitButton_ = std::make_shared<Button>(sf::Vector2f(0.f, 0.f), "exit");
	pExitButton_->setButtonPosition(20.f, rw->getSize().y - 50.f);
	pOptionButton_ = std::make_shared<Button>(sf::Vector2f(0.f, 0.f), "option");
	pOptionButton_->setButtonPosition(20.f, pExitButton_->getButtonPosition().y - 50.f);
	pPlayButton_ = std::make_shared<Button>(sf::Vector2f(0.f, 0.f), "play");
	pPlayButton_->setButtonPosition(20.f, pExitButton_->getButtonPosition().y - 100.f);

	isClickedExit_		= false;
	isClickedPlay_		= false;
	isClickedOption_	= false;
}

StateMenu::~StateMenu()
{
}

void StateMenu::Update(Framework *framework)
{
	pExitButton_->Hover(framework->pRenderWindow);
	isClickedExit_ = pExitButton_->Click(framework->pRenderWindow);

	pOptionButton_->Hover(framework->pRenderWindow);
	isClickedOption_ = pOptionButton_->Click(framework->pRenderWindow);

	pPlayButton_->Hover(framework->pRenderWindow);
	isClickedPlay_ = pPlayButton_->Click(framework->pRenderWindow);
}

void StateMenu::Render(sf::RenderWindow *rw)
{
	pPlayButton_->Render(rw);
	pOptionButton_->Render(rw);
	pExitButton_->Render(rw);
}


void StateMenu::HandleEvents(Framework *framework)
{
	if (isClickedExit_)
	{
		framework->setRun(false);
	}
	if (isClickedPlay_)
	{
		this->loadMusic("start.wav");
		this->playMusic();
		framework->changeState(Framework::gameStates::PLAY);
		resetButton();
	}

	if (isClickedOption_)
	{
		framework->changeState(Framework::gameStates::OPTION);
		resetButton();
	}
}

void StateMenu::resetButton()
{
	isClickedExit_		= false;
	isClickedOption_	= false;
	isClickedPlay_		= false;
}