#include "textbox.h"

TextBox::TextBox()
{
}

Forms::textBoxID TextBox::getName()
{
    return boxID;
}

void TextBox::enableMask(bool enabled)
{
    maskEnabled = enabled;
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
        }

    }
    else selected = false;
}

void TextBox::init(Forms::textBoxID boxName, sf::Vector2f pos, Fonts::ID_InMenu id)
{
    boxID = boxName;

    position.x = pos.x;
    position.y = pos.y;

    boxSprite.setPosition(position);
    boxSprite.setTexture(textureHolderMenu.get(Textures::TextBox));

    boxText.setFont(fontHolderMenu.get(id));
    boxText.setPosition(pos.x + 2, pos.y - 7);

    boxMask.setFont(fontHolderMenu.get(id));
    boxMask.setPosition(pos.x + 2, pos.y - 7);

    ifEmpty.setFont(fontHolderMenu.get(id));
    ifEmpty.setPosition(pos.x + 2, pos.y - 7);
    ifEmpty.setString("|");
}

void TextBox::clear()
{
    boxText.setString("");
    boxMask.setString("");

}

std::string TextBox::getText()
{
    return boxText.getString();
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
    else
    {
        if(empty)
        visible = false;
    }

}

void TextBox::processEvents(sf::Event event)
{
    if(selected)
    {
        if(event.key.code != 8)
            {
            empty = false;
            char lit;
            lit = event.text.unicode;
            boxText.setString(boxText.getString() + lit);
            boxMask.setString(boxMask.getString() + "*");
            }

        else
            {
            std::string str = boxText.getString();
            std::string strMask = boxMask.getString();

            if(str.size() > 0)
                {
                    empty = false;

                    if(str.size() > 1)
                        str.erase(str.size() - 1);
                    else str.clear();
                }
            else empty = true;

            if(strMask.size() > 0)
                {
                    empty = false;
                    if(strMask.size() > 1)
                        strMask.erase(str.size() - 1);
                    else strMask.clear();
                }
            else empty = true;


            boxText.setString(str);
            boxMask.setString(strMask);

            }
    }
    else visible = false;
}
