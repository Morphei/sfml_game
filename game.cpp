#include "game.h"
#include <iostream>


Game::Game(): mWindow(sf::VideoMode(640, 480), "Arms Race"/*, sf::Style::Fullscreen*/)
{
    mWindow.setFramerateLimit(0);
    mWindow.setVerticalSyncEnabled(true);
//    EntityState::statsOfEntity st;
//    st.hitPoints = 100;
//    st.manaPoints = 100;
//    mWorld.initPlayer(EntityState::typeOfEntity::Amazon, "Test", sf::Vector2f(3200,1050), st);

    debug.setFont(fontHolder.get(Fonts::MainFontGame));
    debug.setCharacterSize(20);
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
            std::string str = "FPS: " + std::to_string(int(1.f/timeSinceLastUpdate.asSeconds()));

            debug.setString(str);
            while(timeSinceLastUpdate >= TimePerFrame)
                {
                    timeSinceLastUpdate -= TimePerFrame;
                    processEvents();
                    update(TimePerFrame);
                }
            render();
    }
}

//void Game::init(Player* pl)
//{
//    mWorld.initPlayer(pl);
//}


void Game::processEvents()
{
    sf::Event event;

    while (mWindow.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
            {
                sender.exitGame();
                mWindow.close();
                gameState = States::Menu;
            }

            if(event.type == sf::Event::MouseButtonPressed)
            {
                if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
                {
                        sf::Vector2i pixelPos = sf::Mouse::getPosition(mWindow);
                        sf::Vector2f pos = mWindow.mapPixelToCoords(pixelPos);
                        mWorld.clickPlayer(pos);
//                        sender.sendMouseClick(pos);
                }
            }

            if(event.type == sf::Event::KeyPressed)
            {
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                {
                    sender.exitGame();
                    gameState = States::Menu;
                    mWindow.close();
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
    debug.setPosition(sf::Vector2f(mWindow.getView().getCenter().x - mWindow.getSize().x/2 + 20,
                                   mWindow.getView().getCenter().y - mWindow.getSize().y/2 + 20));
    mWindow.draw(debug);
    mWindow.display();
}

bool Game::started()
{
    return isRunning;
}

void Game::exit()
{
    sender.unbind();
    isRunning = false;
    mWindow.close();
}
