#ifndef APPLICATION_H
#define APPLICATION_H
#include "gamestates.h"
#include "resourcemanager.h"
#include "game.h"
#include "menu.h"
#include "player.h"


//TODO List
//
//  1. Деструктори і вивільнення пам'яті після завершення конкретного State
//  2.
//
//

class Application
{
public:
    Application();
    void run();
    void setState(States::ID id);
    void runGame();
    void setPlayer(sf::Packet packet);
    Menu* menuPointer = nullptr;
    Game* gamePointer = nullptr;

private:

    sf::Packet playerPacket;
    ResourceManager manager;
};

#endif // APPLICATION_H
