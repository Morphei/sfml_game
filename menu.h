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
    void run();

private:
    void createLoginForm();
    void registerPlayer();
    void render();
    void update(sf::Time deltaTime);
    void processEvents();
    void startNew();
    void exit();


private:
    //MessageSender sender;

    sf::String str;

    Form* form;

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
