#include "Button.h"

#include <iostream>

Button::Button(sf::Vector2f position, std::string textOnButton)
{
	pTextureButton = new sf::Texture;
	pTextureButton->loadFromFile("..\\Resources\\Images\\button.png");

	pSpriteButton = new sf::Sprite;
	pSpriteButton->setTexture(*pTextureButton);
	pSpriteButton->setTextureRect(sf::IntRect(0,0,(int)pSpriteButton->getGlobalBounds().width,(int)pSpriteButton->getGlobalBounds().height/2));
	pSpriteButton->setPosition(position);

	//sf::Image subimage;
	//subimage.loadFromFile("mouse_hyper.jpeg");
	//subimage.createMaskFromColor(sf::Color::White);
	//pTextureMouseHyper = new sf::Texture;
	//pTextureMouseHyper->loadFromImage(subimage);
	//pSpriteMouseHyper = new sf::Sprite;
	//pSpriteMouseHyper->setTexture(*pTextureMouseHyper);
	//pSpriteMouseHyper->setOrigin(pTextureMouseHyper->getSize().x / 2, pTextureMouseHyper->getSize().y / 2);
	//pSpriteMouseHyper->setScale(0.2f, 0.2f);

	pFont = new sf::Font;
	pFont->loadFromFile("..\\Resources\\Fonts\\arial.ttf");
	textButton_.setFont(*pFont);
	textButton_.setString(textOnButton);
	textButton_.setPosition(position);

	hovered_	= false;
	clicked_	= false;
}

Button::~Button()
{
	delete pTextureButton;
	delete pSpriteButton;
	delete pFont;
	//delete pSpriteMouseHyper;
	//delete pTextureMouseHyper;

	pTextureButton	= nullptr;
	pSpriteButton	= nullptr;
	pFont			= nullptr;
	//pSpriteMouseHyper	= nullptr;
	//pTextureMouseHyper= nullptr;
}

bool Button::Hover(sf::RenderWindow *rw)
{
	if (sf::Mouse::getPosition(*rw).x > pSpriteButton->getPosition().x &&
		sf::Mouse::getPosition(*rw).y > pSpriteButton->getPosition().y &&
		sf::Mouse::getPosition(*rw).x < pSpriteButton->getPosition().x + pSpriteButton->getGlobalBounds().width &&
		sf::Mouse::getPosition(*rw).y < pSpriteButton->getPosition().y + pSpriteButton->getGlobalBounds().height)
	{
		hovered_ = true;
		pSpriteButton->setTextureRect(sf::IntRect(0, (int) pSpriteButton->getGlobalBounds().height, (int) pSpriteButton->getGlobalBounds().width, (int) pSpriteButton->getGlobalBounds().height));
		return true;
	}

	if (sf::Mouse::getPosition(*rw).x < pSpriteButton->getPosition().x ||
		sf::Mouse::getPosition(*rw).y < pSpriteButton->getPosition().y ||
		sf::Mouse::getPosition(*rw).x > pSpriteButton->getPosition().x + pSpriteButton->getGlobalBounds().width ||
		sf::Mouse::getPosition(*rw).y > pSpriteButton->getPosition().y + pSpriteButton->getGlobalBounds().height)
	{
		hovered_ = false;
		pSpriteButton->setTextureRect(sf::IntRect(0, 0, (int)pSpriteButton->getGlobalBounds().width, (int)pSpriteButton->getGlobalBounds().height));
		return false;
	}

	else 
	{
		return false;
	}
}

bool Button::Click(sf::RenderWindow * rw)
{
	if (hovered_ && sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		clicked_ = true;
		return true;
	}
	else
	{
		clicked_ = false;
		return false;
	}
}

void Button::Render(sf::RenderWindow * rw)
{
	rw->draw(*pSpriteButton);
	rw->draw(textButton_);
	//rw->draw(*pSpriteMouseHyper);
}

void Button::setButtonPosition(float x, float y)
{
	pSpriteButton->setPosition(x, y);
	textButton_.setPosition(x + (pSpriteButton->getGlobalBounds().width / 2) - (textButton_.getGlobalBounds().width), y + (pSpriteButton->getGlobalBounds().height / 2) - (textButton_.getGlobalBounds().height));
}

void Button::setButtonText(std::string buttonText)
{
	textButton_.setString(buttonText);
}
