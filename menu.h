#ifndef MENU_H
#define MENU_H


#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include "resourcemanager.h"
#include "gamestates.h"
#include "button.h"
#include "formmanager.h"


class Menu
{
public:
    Menu();
    Player run();
    void createLoginForm();
    void createChooseCharactersForm();
    void exit();
    void close();
    void startNew();
    Form* form;
    void initPlayer(EntityState::typeOfEntity id, sf::Vector2f position, EntityState::statsOfEntity stats);

private:
    Player player;

    void render();
    void update(sf::Time deltaTime);
    void processEvents();




private:

    sf::String str;

    FormManager formManager;

    sf::Time TimePerFrame = sf::seconds(1.f/60.f);

    sf::Vector2f cursorPosition;
    sf::Vector2i pixelPos;

    std::vector<Button> buttons;
    std::vector<Button>::iterator itr;

    sf::RenderWindow mWindow;

    sf::Sprite background;

};

#endif // MENU_H
