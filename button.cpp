#include "button.h"

Button::Button(Forms::buttonID id, Textures::ID_InMenu up, Textures::ID_InMenu down, sf::String caption, sf::Vector2f pos)
{
    buttonID = id;

    spriteNormal.setTexture(textureHolderMenu.get(up));
    spriteClicked.setTexture(textureHolderMenu.get(down));

    text = caption;

    position = pos;

    spriteClicked.setPosition(position);
    spriteNormal.setPosition(position);

    currentSprite = spriteNormal;
    isText = true;
}

Button::Button(Forms::buttonID id, Textures::ID_InMenu up, Textures::ID_InMenu down, sf::Vector2f pos)
{
    buttonID = id;

    spriteNormal.setTexture(textureHolderMenu.get(up));
    spriteClicked.setTexture(textureHolderMenu.get(down));

    position = pos;

    spriteClicked.setPosition(position);
    spriteNormal.setPosition(position);

    currentSprite = spriteNormal;
    isText = false;
}

bool Button::checkClick(sf::Vector2f mousePos)
{
    if(currentSprite.getGlobalBounds().contains(mousePos.x, mousePos.y))
    {
        currentSprite = spriteClicked;
        pressed = true;
        dt = toPressed;
        return true;
    }
    else
        return false;
}

Forms::buttonID Button::getID()
{
    return buttonID;
}

void Button::update()
{
    if(pressed)
    {

        dt -= sf::milliseconds(50.f);

        if(dt == sf::Time::Zero)
        {
            pressed = false;
        }
    }
    else
        currentSprite = spriteNormal;
}

void Button::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(currentSprite);
}
