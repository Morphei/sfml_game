#ifndef TEXTBOX_H
#define TEXTBOX_H

#include <SFML/Graphics.hpp>
#include <resourcemanager.h>

class TextBox : public sf::Drawable
{
public:
    TextBox();

    bool isSelected();
    bool checkClick(sf::Vector2f cursorPos);
    void init(sf::Vector2f pos, Fonts::ID_InMenu id);
    void clear();
    sf::Text getText();
    void update(sf::Time deltaTime);
    void processEvents(sf::Event);

private:
    bool selected = false;
    bool visible = true;
    bool empty = true;

    float dt;
    float timeToFlick = 1;

    sf::Text ifEmpty;
    sf::Sprite boxSprite;
    sf::Text boxText;
    sf::Vector2f position;

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        target.draw(boxSprite);

        if(visible)
        target.draw(boxText);
    }

};

#endif // TEXTBOX_H
