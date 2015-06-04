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
        for(auto i = buttons.begin(); i != buttons.end(); i++)
            (*i).update();
    }
}

void Form::setCaption(std::string text)
{

}

void Form::addTextBox(Forms::textBoxID boxName ,sf::Vector2f position, Fonts::ID_InMenu id, bool enableMask)
{
    TextBox box;

    box.init(boxName ,pos + position, id);
    box.enableMask(enableMask);

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

void Form::addButton(Forms::buttonID id, sf::Vector2f position, Textures::ID_InMenu texture_normal, Textures::ID_InMenu texture_pressed)
{
    Button button(id, texture_normal, texture_pressed, position + pos);
    buttons.push_back(button);

}

void Form::createForm(Textures::ID_InMenu id, sf::Vector2f position, Parser* parser)
{
    isExsist = true;

    formSprite.setTexture(textureHolderMenu.get(id));

    formSprite.setPosition(position);

    pos = position;

    menuParser = parser;
}

void Form::checkClick(sf::Vector2f cursorPosition)
{
    for(auto i = textBoxes.begin(); i != textBoxes.end(); i++)
        (*i).checkClick(cursorPosition);
    for(auto i = buttons.begin(); i != buttons.end(); i++)
        if((*i).checkClick(cursorPosition))
        {
            switch ((*i).getID()) {
            case Forms::buttonID::Login:
                {
                bool isEmpty = true;
                    std::string login, pass;
                    for(std::vector<TextBox>::iterator j = textBoxes.begin(); j != textBoxes.end(); j++)
                    {

                        if((*j).getName() == Forms::textBoxID::LoginTextBox)
                        {
                            login = (*j).getText();
                            isEmpty = true;
                            if(login.size() == 0)
                                isEmpty = true;
                        }
                        if((*j).getName() == Forms::textBoxID::PasswordTextBox)
                        {
                            pass = (*j).getText();
                            isEmpty = false;
                            if(pass.size() == 0)
                                isEmpty = true;
                        }
                    }
                    if(!isEmpty)
                        menuParser->login(login, pass);
                }
                break;
            }
        }
}
