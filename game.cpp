#include "game.h"
#include <iostream>


Game::Game(): mWindow(sf::VideoMode(1366, 768), "Arms Race", sf::Style::Fullscreen)
{
    mWindow.setVerticalSyncEnabled(true);
}


void Game::run()
{
    sender.inGame();
    isRunning = true;

    sf::Clock mainClock;
    mainClock.restart();

    mWorld.initMap(Textures::Landscape);

    sf::Time timeSinceLastUpdate = sf::Time::Zero;

    while(mWindow.isOpen())
         {
            timeSinceLastUpdate += mainClock.restart();
            while(timeSinceLastUpdate > TimePerFrame)
                {
                    timeSinceLastUpdate -= TimePerFrame;
                    processEvents();
                    update(TimePerFrame);
                }
            render();
    }
}

void Game::init(Player pl)
{
    mWorld.initPlayer(pl);
}


void Game::processEvents()
{
    sf::Event event;

    while (mWindow.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
            {
                mWindow.close();
                gameState = States::Menu;
            }

            if(event.type == sf::Event::MouseButtonPressed)
            {
                if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
                {
                        sf::Vector2i pixelPos = sf::Mouse::getPosition(mWindow);
                        sf::Vector2f pos = mWindow.mapPixelToCoords(pixelPos);
                        mWorld.movePlayer(pos);
                        sender.sendMouseClick(pos);
                }
            }

            if(event.type == sf::Event::KeyPressed)
            {
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                {
                    sender.exitGame();
                    gameState = States::Menu;
//                    mWindow.close();
                    exit();
                }
            }

        }
}


void Game::update(sf::Time deltaTime)
{
    mWorld.update(deltaTime);
}


void Game::render()
{
    mWindow.clear();
    mWindow.draw(mWorld);
    mWindow.display();
}

bool Game::started()
{
    return isRunning;
}

void Game::exit()
{
    mWindow.close();
}
