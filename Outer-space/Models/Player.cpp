#include "Player.h"
#include <sstream>

Player::Player()
{
	//! \bief Cut a color out of the image 
	//! No need to edit the image with e.g. photoshop
	//! \param Name and path of the player image
	//! \retval Image of the new edit image
	sf::Image subimage;
	subimage.loadFromFile("..\\Resources\\Images\\player.jpg");
	subimage.createMaskFromColor(sf::Color::Black);


	// Player Graphics
	pPlayerTexture = new sf::Texture;
	pPlayerTexture->loadFromImage(subimage);

	pPlayerSprite = new sf::Sprite; 
	pPlayerSprite->setTexture(*pPlayerTexture);
	pPlayerSprite->setScale(0.1f, 0.1f);
	pPlayerSprite->setOrigin((pPlayerTexture->getSize().x / 2.f), pPlayerTexture->getSize().y / 2.f);
	pPlayerSprite->setPosition(sf::Vector2f(400, 525));

	// Shield Graphics
	sf::Image subImageShield;
	subImageShield.loadFromFile("..\\Resources\\Images\\shield_new.png");
	subImageShield.createMaskFromColor(sf::Color::Black);

	pShieldTexture = new sf::Texture;
	pShieldTexture->loadFromImage(subImageShield);

	pShieldSprite = new sf::Sprite;	
	pShieldSprite->setTexture(*pShieldTexture);
	pShieldSprite->setScale(0.2, 0.2);
	pShieldSprite->setPosition(sf::Vector2f(400.f, 525.f));
	pShieldSprite->setOrigin((pShieldTexture->getSize().x / 2), pShieldTexture->getSize().y / 2);

	// Font Graphics
	pFont = new sf::Font;
	pFont->loadFromFile("..\\Resources\\Fonts\\arial.ttf");

	textPunkte_.setFont(*pFont);
	textPunkte_.setCharacterSize(20);
	textPunkte_.setString("Punkte: ");
	textLife_.setFont(*pFont);
	textLife_.setCharacterSize(20);
	textLife_.setString("Leben: ");
	textLife_.setPosition(10.f, 570.f);
	textShield_.setFont(*pFont);
	textShield_.setCharacterSize(20);
	textShield_.setString("Schild: ");
	textShield_.setPosition(10.f, 550.f);

	weapon = new Weapon();
	
	mousePosition_ = sf::Vector2f(0, 0);
	setLife(100);
	setShield(100);
	setIsAlive(true);
	setPoints(0);

	step_ = 255 / getShield();
}

Player::~Player()
{
	delete pPlayerTexture;
	delete pPlayerSprite;
	delete pShieldTexture;
	delete pShieldSprite;
	delete pFont;

	pPlayerTexture	= nullptr;
	pPlayerSprite	= nullptr;
	pShieldTexture	= nullptr;
	pShieldSprite	= nullptr;
	pFont			= nullptr;
}

void Player::update(float frametime)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
	{
		pPlayerSprite->move(-350 * frametime, 0);
	}
		//pShieldSprite->move(-350 * frametime, 0);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
		pPlayerSprite->move(350 * frametime, 0);
		//pShieldSprite->move(350 * frametime, 0);

	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
		weapon->fire();

	// TODO : nachlesen!
	pShieldSprite->setColor(sf::Color(pShieldSprite->getColor().r, pShieldSprite->getColor().g, pShieldSprite->getColor().b, (getShield()*step_)));
	pShieldSprite->setPosition(pPlayerSprite->getPosition());

	if (getLife() < 0 || getLife() == 0)
	{
		setIsAlive(false);
	}

	weapon->update(mousePosition_, pPlayerSprite->getPosition(), frametime);

	std::stringstream points;
	points << points_;
	textPunkte_.setString("Punkte: " + points.str() );
	std::stringstream health;
	health << life_;
	textLife_.setString("Leben: " + health.str());
	std::stringstream shield;
	shield << shield_;
	textShield_.setString("Schild:  " + shield.str());
}

void Player::render(sf::RenderWindow *rw)
{
	mousePosition_ = static_cast<sf::Vector2f>(sf::Mouse::getPosition(*rw));
	weapon->render(rw);

	rw->draw(*pShieldSprite);
	rw->draw(*pPlayerSprite);
	rw->draw(textPunkte_);
	rw->draw(textLife_);
	rw->draw(textShield_);
}

void Player::handle(Framework *framework)
{
	if (pPlayerSprite->getPosition().x > framework->pRenderWindow->getSize().x)
	{
		pPlayerSprite->setPosition(framework->pRenderWindow->getSize().x, pPlayerSprite->getPosition().y);
	}
	if (pPlayerSprite->getPosition().x < 0)
	{
		pPlayerSprite->setPosition(0, pPlayerSprite->getPosition().y);
	}
}

void Player::setLife(float life)
{
	life_ = life;
}

void Player::setIsAlive(bool isAlive)
{
	isAlive_ = isAlive;
}

void Player::setPoints(float points)
{
	points_ = points;
}

void Player::setShield(float shield)
{
	shield_ = shield;
}

