#ifndef APPLICATION_H
#define APPLICATION_H
#include "gamestates.h"
#include "resourcemanager.h"
#include "game.h"
#include "menu.h"

#include "parser.h"

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

private:

    //Parser parser;
    ResourceManager manager;
};

#endif // APPLICATION_H
