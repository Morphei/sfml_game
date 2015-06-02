#include <iostream>
#include "form.h"

Form::Form()
{

}

bool Form::exsist()
{
    return isExsist;
}

void Form::processEvents(sf::Event event)
{
    for(auto i = textBoxes.begin(); i != textBoxes.end(); i++)
        if((*i).isSelected())
            (*i).processEvents(event);
}

void Form::update(sf::Time deltaTime)
{
    if(isClosed)
        isExsist = false;
    else
    {
        for(auto i = textBoxes.begin(); i != textBoxes.end(); i++)
            (*i).update(deltaTime);
    }
}

void Form::setCaption(std::string text)
{

}

void Form::addTextBox(sf::Vector2f position, Fonts::ID_InMenu id)
{
    TextBox box;
    box.init(pos + position, id);
    textBoxes.push_back(box);
}

void Form::addLabel(sf::Vector2f position, std::string text, Fonts::ID_InMenu fontID)
{
    sf::Text label;
    label.setFont(fontHolderMenu.get(fontID));
    label.setString(text);
    label.setPosition(position + pos);
    labels.push_back(label);
}

void Form::createForm(Textures::ID_InMenu id, sf::Vector2f position)
{
    isExsist = true;

    formSprite.setTexture(textureHolderMenu.get(id));

    formSprite.setPosition(position);

    pos = position;

    closeButton = new Button(Textures::CloseButton, Textures::CloseButtonPressed, pos.x + 10, pos.y + 10);
}

void Form::checkClick(sf::Vector2f cursorPosition)
{
    if(closeButton->checkClick(cursorPosition))
    {
        isClosed = true;
    }
    for(auto i = textBoxes.begin(); i != textBoxes.end(); i++)
        (*i).checkClick(cursorPosition);
}
