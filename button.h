#ifndef BUTTON_H
#define BUTTON_H

#include <SFML/Graphics.hpp>
#include "resourcemanager.h"
#include "gamestates.h"

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
    void setVisible(bool isVis);

    Button(Forms::buttonID id, Textures::ID_InMenu, Textures::ID_InMenu, sf::String caption, sf::Vector2f pos);
    Button(Forms::buttonID id, Textures::ID_InMenu, Textures::ID_InMenu, sf::Vector2f pos);

    bool checkClick(sf::Vector2f mousePos);

    Forms::buttonID getID();

    void update();

private:
    bool visible = true;

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    Forms::buttonID buttonID;

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
