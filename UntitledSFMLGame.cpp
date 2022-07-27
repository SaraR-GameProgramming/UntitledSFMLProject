// UntitledSFMLGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Player.h"

sf::RenderWindow window(sf::VideoMode(1024, 768), "SFML Game");

// game textures
sf::Texture backgroundTexture;
sf::Texture playerTexture;
// game sprites
sf::Sprite backgroundSprite;
sf::Sprite playerSprite;

Player myPlayer;

sf::Vector2f playerPos;
bool isPlayerMovingRight{ false };
bool isPlayerMovingLeft{ false };



void updateMovement(float dt)
{
    if (isPlayerMovingRight)
    {
        playerSprite.move(20.0f * dt, 0);
    }
    if (isPlayerMovingLeft)
    {
        playerSprite.move(-20.0f * dt, 0);
    }

    myPlayer.updateMovement(dt);
    
}

int main()
{
    //clock
    sf::Clock clock;

    // loading the texture
    backgroundTexture.loadFromFile("GameGraphics/bg.png");
    backgroundSprite.setTexture(backgroundTexture);

    myPlayer.init("GameGraphics/bunny.png", sf::Vector2f(1024 / 2, 768 / 2), 200);

  /*  playerTexture.loadFromFile("GameGraphics/bunny.png");
    playerSprite.setTexture(playerTexture);
    playerSprite.setPosition(sf::Vector2f(1024 / 2, 768 / 2));
    playerSprite.setScale(3, 3);*/


    

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::KeyPressed)
            {
                if(event.key.code == sf::Keyboard::Up)
                {
                    myPlayer.jump(750.0f);
                    std::cout << "player has jumped" << std::endl;
                }
            }

            // updateinput
            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Right)
                {
                    isPlayerMovingRight = true;
                    std::cout << "player has moved Right" << std::endl;
                }
                if (event.key.code == sf::Keyboard::Left)
                {
                    isPlayerMovingLeft = true;
                    std::cout << "player has moved Left" << std::endl;
                }

            }

            if (event.type == sf::Event::KeyReleased)
            {
                if (event.key.code == sf::Keyboard::Right)
                {
                    isPlayerMovingRight = false;
                    std::cout << "player has stopped moving" << std::endl;
                }

                if (event.key.code == sf::Keyboard::Left)
                {
                    isPlayerMovingLeft = false;
                    std::cout << "player has stopped moving" << std::endl;
                }
            }


            if (event.key.code == sf::Keyboard::Escape || event.type == sf::Event::Closed)
                window.close();
            
            // Update Game
            sf::Time dt = clock.restart();
            updateMovement(dt.asSeconds());
            /*if (event.type == sf::Event::Closed)
                window.close();*/
        }

        window.clear();
        // drawing the background for the game
        window.draw(backgroundSprite);
        window.draw(myPlayer.getSprite());
        window.display();
    }



    return 0;

}
