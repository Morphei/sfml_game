#include "application.h"
#include "networkoperator.h"

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
                menu.run();
            }
            break;

            case States::Game:
            {
                Game game;
                game.run();
            }
            break;

            case States::Close:

            break;
        }
    }
}

void Application::setState(States::ID id)
{
    gameState = id;
}
