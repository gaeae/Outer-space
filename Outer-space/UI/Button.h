#pragma once

#include "Gui.h"

class Button :  public GUI
{
public:

	Button(sf::Vector2f position, std::string textOnButton);
	~Button();

	// override -> virtuelle Funktionen von GUI sollen überschrieben werden.
	bool Hover	(sf::RenderWindow *rw) override;
	bool Click	(sf::RenderWindow *rw) override;
	void Render		(sf::RenderWindow *rw) override;

	void setButtonPosition(float x, float y);

	sf::Vector2f getButtonPosition() { return pSpriteButton->getPosition(); };
	bool getClicked() { return clicked_; };

	void setButtonText(std::string buttonText);

protected:

private:

	sf::Texture *pTextureButton;
	//sf::Texture	*pTextureMouseHyper;
	sf::Sprite	*pSpriteButton;
	//sf::Sprite	*pSpriteMouseHyper;
	sf::Font	*pFont;
	sf::Text	textButton_;
};