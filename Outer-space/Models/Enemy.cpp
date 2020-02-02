#include "Enemy.h"
#include <iostream>

Enemy::Enemy(sf::Texture &texture)
{
	speed_ = 0.4f;
	health_ = 100.f;
	damage_ = 10.f;
	isAlive_ = true;

	this->setTexture(texture);
	this->setOrigin(texture.getSize().x / 2, texture.getSize().y / 2);
	this->setScale(0.9, 0.9);
}

Enemy::~Enemy()
{
}

void Enemy::update(float elapsedTime)
{
	//TODO KI Implementieren 
}

void Enemy::render(sf::RenderWindow *rw)
{
	rw->draw(*this);
}

void Enemy::setName(std::string name)
{
	name_ = name;
}

void Enemy::setHealth(float health)
{
	health_ = health;
}

void Enemy::setIsAlive(bool isAlive)
{
	isAlive_ = isAlive;
}

void Enemy::setSpeed(float speed)
{
	speed_ = speed;
}

void Enemy::setDamage(float damage)
{
	damage_ = damage;
}