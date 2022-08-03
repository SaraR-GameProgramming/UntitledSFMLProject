#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <iostream>

class Player
{
private:
	sf::Sprite sprite;
	sf::Texture texture;

	float playerSpeed;
	// private func
	void initTexture();
	void initSprite();
public:
	Player();
	virtual ~Player();

	// Functions

	void move(const float direction_x, const float direction_y);

	void update();

	void render(sf::RenderTarget& target);
};

