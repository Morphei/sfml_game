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
                menu.run();
                //delete menuPointer;
            }
            break;

            case States::Game:
            {
                Game game;
                gamePointer = &game;
                game.run();
                //delete gamePointer;
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
