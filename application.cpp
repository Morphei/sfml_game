#include "application.h"

Application::Application()
{
    setState(States::Menu);//TODO: Changed to intro
    manager.load();
}

void Application::run()
{
    while(gameState != States::Close)
    {
        switch (gameState)
        {
            case States::Intro:

            break;

            case States::Menu:
            {
                Menu menu;
                menuPointer = &menu;
                player = menu.run();
                //delete menuPointer;
            }
            break;

            case States::Game:
            {
                Game game(player);
                gamePointer = &game;
                game.run();
                //game.mWorld.initPlayer();
                //delete gamePointer;
            }
            break;

            case States::Close:
            {
                delete gamePointer;
                delete menuPointer;
            }
            break;
        }
    }
}

void Application::setState(States::ID id)
{
    gameState = id;
}

void Application::runGame()
{
    run();
}

void Application::setPlayer(sf::Packet packet)
{
    playerPacket = packet;
}
