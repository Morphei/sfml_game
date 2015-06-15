#ifndef GAME_H
#define GAME_H

#include "game.h"
#include "world.h"
#include "gamestates.h"
#include "resourcemanager.h"
//#include "networkoperator.h"

#include "messagesender.h"

#include <SFML/Graphics.hpp>
//              TODO List
//  1. Клас Player, взаємодія його з сервером
//  2. Клас Enemy
//  3. Наслідування цих двох класів від Entiny (віртуальний?) +
//  4. Пауза
//      4.1 На Esc
//  5. Відмальовка інфи про гравця, HP, Mana, etc.
//  6. Чат?)
//  7. Центровка камери на гравці
//  8. Відсилання event на сервер
//  9. Інвентар на кл.Tab
//  10. Обробник подій
//  11. Мінікарта
//  12. Move не на клік, а поки натиснута клавіша миші

// Paladin Sprites!!



const sf::Time TimePerFrame = sf::seconds(1.f/60.f);

class Game
{
public:
                Game();
    void        run();
    bool        started();
    void exit();

    World mWorld;

private:
    void        init(Player *pl);
    void        processEvents();
    void        update(sf::Time deltaTime);
    void        render();


    bool isRunning = false;
private:

    MessageSender sender;
//    NetworkOperator netOperator;

    sf::RenderWindow mWindow;
};

#endif // GAME_H
