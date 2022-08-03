// UntitledSFMLGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include "Game.h"







int main()
{
    //init game
    Game game;
    ////clock
    sf::Clock clock;

    while (game.isRunning())
    {
        //Updates
        game.Update();
        //Rendering
        game.Render();

    }
  

}



//// game textures
//sf::Texture backgroundTexture;
//sf::Texture playerTexture;
//// game sprites
//sf::Sprite backgroundSprite;
//sf::Sprite playerSprite;
//
//
//
//sf::Vector2f playerPos;
//bool isPlayerMovingRight{ false };
//bool isPlayerMovingLeft{ false };
//
//
//
//void updateMovement(float dt)
//{
//    if (isPlayerMovingRight)
//    {
//        playerSprite.move(5.0f * dt, 0);
//    }
//    if (isPlayerMovingLeft)
//    {
//        playerSprite.move(-5.0f * dt, 0);
//    }
//    
//}


//// loading the textures old
    //backgroundTexture.loadFromFile("GameGraphics/bg.png");
    //backgroundSprite.setTexture(backgroundTexture);



    //playerTexture.loadFromFile("GameGraphics/bunny.png");
    //playerSprite.setTexture(playerTexture);
    //playerSprite.setPosition(sf::Vector2f(screenSize.x / 2, screenSize.y / 2));
    //playerSprite.setOrigin(playerTexture.getSize().x / 2, playerTexture.getSize().y / 2);
    //playerSprite.setScale(4, 4);


//sf::Event event;
//while ()
//{
//    if (event.type == sf::Event::KeyPressed)
//    {
//        if (event.key.code == sf::Keyboard::Up)
//        {
//
//            std::cout << "player has jumped" << std::endl;
//        }
//    }
//
//    // updateinput
//    if (event.type == sf::Event::KeyPressed)
//    {
//        if (event.key.code == sf::Keyboard::Right)
//        {
//            isPlayerMovingRight = true;
//            std::cout << "player has moved Right" << std::endl;
//        }
//        if (event.key.code == sf::Keyboard::Left)
//        {
//            isPlayerMovingLeft = true;
//            std::cout << "player has moved Left" << std::endl;
//        }
//
//    }
//
//    if (event.type == sf::Event::KeyReleased)
//    {
//        if (event.key.code == sf::Keyboard::Right)
//        {
//            isPlayerMovingRight = false;
//            std::cout << "player has stopped moving" << std::endl;
//        }
//
//        if (event.key.code == sf::Keyboard::Left)
//        {
//            isPlayerMovingLeft = false;
//            std::cout << "player has stopped moving" << std::endl;
//        }
//    }
//
//
//    if (event.key.code == sf::Keyboard::Escape || event.type == sf::Event::Closed)
//        window.close();
//
//    // Update Game
//    sf::Time dt = clock.restart();
//    updateMovement(dt.asSeconds());
//    /*if (event.type == sf::Event::Closed)
//        window.close();*/
//}
//
//window.clear();
//// drawing the background for the game
//window.draw(backgroundSprite);
//
//window.draw(playerSprite);
//window.display();
//    }