#include "Game.h"



// Private Functions

void Game::initPlayer()
{
	this->player = new Player();
}

void Game::initVariables()
{
	this->window = nullptr;
}

void Game::intiWindow()
{
	this->vm.height = 768;
	this->vm.width = 1024;
	this->window = new sf::RenderWindow(this -> vm, "SFML Game", sf::Style::Titlebar | sf::Style::Close);
	this->window->setFramerateLimit(90);
	this->window->setVerticalSyncEnabled(false);
}

// Constructor / Deconstructor

Game::Game()
{
	this->initVariables();
	this->intiWindow();
	this->initPlayer();
}

Game::~Game()
{
	delete this->window;
	delete this->player;
}

const bool Game::isRunning() const
{
	return this->window->isOpen();
}

// Public Functions

void Game::EventUpdate()
{
	while (this->window->pollEvent(this->eve))
	{
		if (this->eve.type == sf::Event::Closed)
			this->window->close();
		if (this->eve.KeyPressed && eve.key.code == sf::Keyboard::Escape)
			this->window->close();


	}

	// player movement
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
	{
		this->player->move(-1.0f, 0.0f);
		std::cout << "Player is moving Left" << std::endl;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
	{
		this->player->move(1.0f, 0.0f);
		std::cout << "Player is moving Right" << std::endl;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
	{
		this->player->move(0.0f, -1.0f);
		std::cout << "Player is moving Up" << std::endl;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
	{
		this->player->move(0.0f, 1.0f);
		std::cout << "Player is moving Down" << std::endl;
	}
}

void Game::Update()
{
		
	this->EventUpdate();
	
}



void Game::Render()

/* Renders all game objects */
{
	this->window->clear();

	this->player->render(*this->window);

	this->window->display();
}
