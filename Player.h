#pragma once
#include <SFML/Graphics.hpp>
class Player
{
private:
	sf::Texture m_texture;
	sf::Sprite m_sprite;
	sf::Vector2f m_position;

	int jumpCount = 0;
	float m_mass;
	float m_velocity;
	float m_force;
	const float m_gravity = 9.80f;
	bool m_isGrounded;
public:
	Player(); // constructor
	~Player(); // deconstructor

	void init(std::string textureName, sf::Vector2f position, float mass);
	void updateMovement(float dt);
	void jump(float velocity);
	sf::Sprite getSprite();
};

