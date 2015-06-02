#include "button.h"

Button::Button(Textures::ID_InMenu up, Textures::ID_InMenu down, sf::String caption, int posX, int posY)
{
    spriteNormal.setTexture(textureHolderMenu.get(up));
    spriteClicked.setTexture(textureHolderMenu.get(down));

    text = caption;

    position.x = posX;
    position.y = posY;

    spriteClicked.setPosition(position);
    spriteNormal.setPosition(position);

    currentSprite = spriteNormal;
    isText = true;
}

Button::Button(Textures::ID_InMenu up, Textures::ID_InMenu down, int posX, int posY)
{
    spriteNormal.setTexture(textureHolderMenu.get(up));
    spriteClicked.setTexture(textureHolderMenu.get(down));

    position.x = posX;
    position.y = posY;

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
