#include "StatePlay.h"

StatePlay::StatePlay(sf::RenderWindow * rw)
{
	rw->setMouseCursorVisible(false);

	pFrameClock		= new sf::Clock;
	
	frameTime_ = 0.f;
	elapsedTime_ = 0.f;

	sf::Image subimage;
	subimage.loadFromFile("mouse2.png");
	subimage.createMaskFromColor(sf::Color::Black);

	pMouseTexture	= new sf::Texture;
	pMouseSprite	= new sf::Sprite;

	pMouseTexture->loadFromImage(subimage);
	pMouseSprite->setTexture(*pMouseTexture);
	pMouseSprite->setOrigin(pMouseTexture->getSize().x / 2.f, pMouseTexture->getSize().y / 2.f);
	pMouseSprite->setScale(0.2f, 0.2f);

	pPlayer				= new Player;
	pManagerAsteroid	= new AsteroidManager;
	pCollisionSystem	= new CollisionSystem(pMouseSprite, pPlayer, pManagerAsteroid->getList());

	textureEnemy.loadFromFile("enemy.png");
	uniqueEnemy = std::make_unique<Enemy>(textureEnemy);
	uniqueEnemy->setPosition(400.f, 65.f);
}

StatePlay::~StatePlay()
{

	delete pPlayer;
	delete pManagerAsteroid;
	delete pCollisionSystem;
	delete pFrameClock;
	delete pMouseSprite;
	delete pMouseTexture;

	pPlayer				= nullptr;
	pManagerAsteroid	= nullptr;
	pCollisionSystem	= nullptr;
	pFrameClock			= nullptr;
	pMouseSprite		= nullptr;
	pMouseTexture		= nullptr;
}

void StatePlay::HandleEvents(Framework *game)
{
	pPlayer->handle(game);
	pManagerAsteroid->handle();
	if (!pPlayer->getIsAlive())
	{	
		game->pRenderWindow->setMouseCursorVisible(true);
		game->changeState(Framework::gameStates::MAINMENU);
	}
}

void StatePlay::Update(Framework *game)
{
	frameTime_ = pFrameClock->getElapsedTime().asSeconds();
	elapsedTime_ += frameTime_;

	pPlayer->update(frameTime_);
	pManagerAsteroid->update(frameTime_);
	pCollisionSystem->update(frameTime_);
	pMouseSprite->setPosition(static_cast<sf::Vector2f>(sf::Mouse::getPosition(*(game->pRenderWindow))));
	uniqueEnemy->update(frameTime_);

	pFrameClock->restart();
}

void StatePlay::Render(sf::RenderWindow *rw)
{
	pManagerAsteroid->render(rw);
	pPlayer->render(rw);
	uniqueEnemy->render(rw);
	rw->draw(*pMouseSprite);
}

