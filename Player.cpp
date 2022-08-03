#include "Player.h"

void Player::initTexture()
{
	// loading texture from file
	if (!this->texture.loadFromFile("GameGraphics/bunny.png"))
	{
		// image not found
		std::cout << "ERRPR::PLAYER::INITTEXTURE:: unable to load from file" << std::endl;
		std::cout << "bunn bunn not found" << std::endl;
	}
}

void Player::initSprite()
{
	// setting texture for sprite
	this->sprite.setTexture(this->texture);

	// resize sprite
	this->sprite.setScale(3.0f, 3.0f);
}

Player::Player()
{
	this->playerSpeed = 2.5f;
	this->initTexture();
	this->initSprite();
}

Player::~Player()
{
}

void Player::move(const float direction_x, const float direction_y)
{
	this->sprite.move(this->playerSpeed * direction_x, this->playerSpeed * direction_y);
}

void Player::update()
{
}

void Player::render(sf::RenderTarget& target)
{
	target.draw(this->sprite);
}
