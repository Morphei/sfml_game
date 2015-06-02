#ifndef BUTTON_H
#define BUTTON_H

#include <SFML/Graphics.hpp>
#include "resourcemanager.h"

//  TODO List
//
//          Додати конструктор, що вміщає текст кнопки:
//  1. Завантаження шрифта
//  2. Створення sf::Text
//  3. Розміщення його по центру кнопки
//  4. Метод Draw замість getCurrentSprite();

class Button : public sf::Drawable
{
public:

    Button(Textures::ID_InMenu, Textures::ID_InMenu, sf::String caption, int posX, int posY);
    Button(Textures::ID_InMenu, Textures::ID_InMenu, int posX, int posY);
    bool checkClick(sf::Vector2f mousePos);
    void update();

private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    sf::Sprite spriteNormal;
    sf::Sprite spriteClicked;
    sf::Sprite currentSprite;
    sf::String text;
    sf::Vector2f position;
    sf::Time toPressed = sf::seconds(1.f/2.f);
    sf::Time dt;

    bool isText;
    bool pressed = false;
};

#endif // BUTTON_H
