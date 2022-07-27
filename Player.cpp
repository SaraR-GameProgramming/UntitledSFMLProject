#include "Player.h"

Player::Player()
{
}

Player::~Player()
{
}

void Player::init(std::string textureName, sf::Vector2f position, float mass)
{
	m_position = position;
	m_mass = mass;

	m_isGrounded = false;
	// load texture
	m_texture.loadFromFile(textureName.c_str());
	// create sprite, attach texture
	m_sprite.setTexture(m_texture);
	m_sprite.setPosition(m_position);
	m_sprite.setOrigin(m_texture.getSize().x / 2, m_texture.getSize().y / 2);
}

void Player::updateMovement(float dt)
{
	m_force -= m_mass * m_gravity * dt;

	m_position.y -= m_force * dt;

	m_sprite.setPosition(m_position);

	if (m_position.y >= 768 * 0.75f)
	{
		m_position.y = 768 * 0.75f;

		m_force = 0;

		m_isGrounded = true;

		jumpCount = 0;
	}

}

void Player::jump(float velocity)
{
	if (jumpCount < 2)
	{
		jumpCount++;

		m_velocity = velocity;
		m_isGrounded = false;
	}
}

sf::Sprite Player::getSprite()
{
	return sf::Sprite();
}
