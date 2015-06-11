#include "application.h"

Application::Application()
{
    setState(States::Game);//TODO: Changed to intro
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
                menuPointer = new Menu;
                menuPointer->run();
                menuPointer = nullptr;
            }
            break;

            case States::Game:
            {
                gamePointer = new Game;
                gamePointer->run();
                gamePointer = nullptr;
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
