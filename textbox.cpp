#include "textbox.h"

TextBox::TextBox()
{
}

bool TextBox::isSelected()
{
    if(selected)
        return true;
    else return false;
}

bool TextBox::checkClick(sf::Vector2f cursorPos)
{
    //    if(textBoxLogin.getGlobalBounds().contains(cursorPosition))
    //    {
    //        playerInputName.setString("|");
    //        selectNameTextBox = true;
    //        changeCursor = true;
    //        isActive = true;
    //        dt = timeToChangeCursor;
    //    }
    //    if(textBoxPassword.getGlobalBounds().contains(cursorPosition))
    //    {
    //        playerInputPass.setString("|");
    //        selectNameTextBox = false;
    //        changeCursor = true;
    //        isActive = true;
    //        dt = timeToChangeCursor;
    //    }
    if(boxSprite.getGlobalBounds().contains(cursorPos))
    {
        if(!selected)
        {
            selected = true;
            boxText = ifEmpty;
        }
    }
    else
    {
        selected = false;
        if(boxText.getString() == '|')
            visible = false;
    }
}

void TextBox::init(sf::Vector2f pos, Fonts::ID_InMenu id)
{
    position.x = pos.x;
    position.y = pos.y;

    boxSprite.setPosition(position);
    boxSprite.setTexture(textureHolderMenu.get(Textures::TextBox));

    boxText.setFont(fontHolderMenu.get(id));
    boxText.setPosition(pos.x + 2, pos.y - 7);

    ifEmpty.setFont(fontHolderMenu.get(id));
    ifEmpty.setPosition(pos.x-2, pos.y - 7);
    ifEmpty.setString("|");
}

sf::Text TextBox::getText()
{
    return boxText;
}

void TextBox::update(sf::Time deltaTime)
{

    if(selected)
    {
        if(empty)
        {
            if(dt < 0)
            {
                dt = timeToFlick;
                visible = !visible;
            }
            dt -= deltaTime.asSeconds();
        }
        else
        {
            visible = true;

        }
    }

}

void TextBox::processEvents(sf::Event)
{

}
