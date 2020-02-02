#include "StateOption.h"

//StateOption::StateOption()
//{
//}

StateOption::StateOption(sf::RenderWindow * rw)
{
	pBackButton_ = std::make_shared<Button>(sf::Vector2f(0.f, 0.f), "back");
	pBackButton_->setButtonPosition(20.f, 50.f);

	// TODO sound wird nicht gemutet und nach jeder rückkehr zur Option ist "music is on"
	pMusicButton_ = std::make_shared<Button>(sf::Vector2f(0.f, 0.f), "music is on");
	pMusicButton_->setButtonPosition(rw->getSize().x / 2.f, rw->getSize().y / 2.f);

	isBackClicked_			= false;
	isMusicButtonClicked_	= false;
	musicToogle_			= false;

}

StateOption::~StateOption()
{
}

void StateOption::Update(Framework *framework)
{
	pBackButton_->Hover(framework->pRenderWindow);
	isBackClicked_ = pBackButton_->Click(framework->pRenderWindow);

	pMusicButton_->Hover(framework->pRenderWindow);
	isMusicButtonClicked_ = pMusicButton_->Click(framework->pRenderWindow);
}

void StateOption::HandleEvents(Framework *framework)
{
	if (isBackClicked_)
	{
		framework->changeState(Framework::gameStates::MAINMENU);

		isMusicButtonClicked_ = false;
	}
	else if (isMusicButtonClicked_)
	{
		if (!musicBotton)
		{
			this->volume(!musicBotton);
			pMusicButton_->setButtonText("music is off");
			std::cout << "Musik aus!" << std::endl;
		}
		else if(musicBotton)
		{
			this->volume(musicBotton);
			pMusicButton_->setButtonText("music is on");
			std::cout << "Musik an!" << std::endl;
		}
		musicBotton = !musicBotton;
		isMusicButtonClicked_ = !isMusicButtonClicked_;
	}
}

void StateOption::Render(sf::RenderWindow * rw)
{
	pBackButton_->Render(rw);
	pMusicButton_->Render(rw);
}

void StateOption::toggle(bool key, bool variable)
{
	if (isMusicButtonClicked_ && key)
	{
		variable = !variable;
	}
	isMusicButtonClicked_ = key;
}
