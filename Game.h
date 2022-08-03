#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

//user made classes include
#include "Player.h"
/*
	Class sets up back end functions.
*/

class Game
{
private:
	//Window

	sf::RenderWindow* window;
	sf::VideoMode vm;
	sf::Event eve;

	Player* player;

	void initPlayer();

	void initVariables();
	void intiWindow();
public:
	// Constructor and deconstructor
	Game();
	virtual ~Game();

	const bool isRunning() const;

	// Functions
	void EventUpdate();
	void Update();
	
	void Render();
};

