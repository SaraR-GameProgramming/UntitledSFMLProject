// UntitledSFMLGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <SFML/Graphics.hpp>
#include <iostream>

sf::RenderWindow window(sf::VideoMode(1024, 768), "SFML Game");

// game textures
sf::Texture backgroundTexture;
sf::Texture playerTexture;
// game sprites
sf::Sprite backgroundSprite;
sf::Sprite playerSprite;

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

    
}

int main()
{
    //clock
    sf::Clock clock;

    // loading the texture
    backgroundTexture.loadFromFile("GameGraphics/bg.png");
    backgroundSprite.setTexture(backgroundTexture);

    playerTexture.loadFromFile("GameGraphics/bunny.png");
    playerSprite.setTexture(playerTexture);
    playerSprite.setPosition(sf::Vector2f(1024 / 2, 768 / 2));
    playerSprite.setScale(3, 3);


    

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            // updateinput
            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Right)
                {
                    isPlayerMovingRight = true;
                }
                if (event.key.code == sf::Keyboard::Left)
                {
                    isPlayerMovingLeft = true;
                }

            }

            if (event.type == sf::Event::KeyReleased)
            {
                if (event.key.code == sf::Keyboard::Right)
                {
                    isPlayerMovingRight = false;
                }

                if (event.key.code == sf::Keyboard::Left)
                {
                    isPlayerMovingLeft = false;
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
        window.draw(playerSprite);
        window.display();
    }



    return 0;

}
