#ifndef TEXTBOX_H
#define TEXTBOX_H

#include <SFML/Graphics.hpp>
#include <resourcemanager.h>
#include "iostream"
#include "gamestates.h"

class TextBox : public sf::Drawable
{
public:
    TextBox();

    Forms::textBoxID getName();
    void enableMask(bool enabled);
    bool isSelected();
    bool checkClick(sf::Vector2f cursorPos);
    void init(Forms::textBoxID boxName, sf::Vector2f pos, Fonts::ID_InMenu id);
    void clear();
    std::string getText();
    void update(sf::Time deltaTime);
    void processEvents(sf::Event event);

private:
    bool selected = false;
    bool visible = false;
    bool empty = true;
    bool maskEnabled = false;

    float dt;
    float timeToFlick = 1;

    Forms::textBoxID boxID;

    sf::Text boxMask;
    sf::Text ifEmpty;
    sf::Sprite boxSprite;
    sf::Text boxText;
    sf::Vector2f position;

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        target.draw(boxSprite);

        if(visible)
        {
            if(!empty)
                if(maskEnabled)
                    target.draw(boxMask);
                else
                    target.draw(boxText);
            else target.draw(ifEmpty);
        }
    }

};

#endif // TEXTBOX_H
