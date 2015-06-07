#include "button.h"

void Button::setVisible(bool isVis)
{
    visible = isVis;
}

Button::Button(Forms::buttonID id, Textures::ID_InMenu up, Textures::ID_InMenu down, sf::String caption, sf::Vector2f pos)
{
    buttonID = id;

    text.setFont(fontHolderMenu.get(Fonts::MainFont));
    text.setString(caption);

    spriteNormal.setTexture(textureHolderMenu.get(up));
    spriteClicked.setTexture(textureHolderMenu.get(down));

    position = pos;

    spriteClicked.setPosition(position);
    spriteNormal.setPosition(position);

    text.setCharacterSize(20);

    text.setColor(sf::Color::Black);

    sf::FloatRect bounds = text.getLocalBounds();
    sf::FloatRect spriteBounds = spriteNormal.getLocalBounds();

    spriteNormal.setOrigin(spriteBounds.width / 2.f, spriteBounds.height/ 2.f);
    spriteClicked.setOrigin(spriteBounds.width / 2.f, spriteBounds.height/ 2.f);

    spriteNormal.scale((bounds.width / spriteBounds.width) + 0.3 , 1.f);
    spriteClicked.scale((bounds.width / spriteBounds.width) + 0.3 , 1.f);

    text.setOrigin(bounds.width / 2.f, bounds.height / 2.f);
    text.setPosition(position.x + spriteNormal.getOrigin().x, position.y + spriteNormal.getOrigin().y);

    spriteNormal.setPosition(position.x + spriteNormal.getOrigin().x, position.y + spriteNormal.getOrigin().y + 5);
    spriteClicked.setPosition(position.x + spriteNormal.getOrigin().x, position.y + spriteNormal.getOrigin().y + 5);

    txtPos = text.getPosition();
    txtPosPressed = sf::Vector2f(text.getPosition().x, text.getPosition().y+2);

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
        text.setColor(sf::Color::Blue);
        text.setPosition(txtPosPressed);
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
            currentSprite = spriteNormal;
            text.setColor(sf::Color::Black);
            text.setPosition(txtPos);
            pressed = false;
        }
    }
    else
    {

    }
}

void Button::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    if(visible)
    target.draw(currentSprite);
    target.draw(text);
}
