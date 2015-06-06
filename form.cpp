#include <iostream>
#include "form.h"

Form::Form()
{

}

bool Form::exsist()
{
    return isExsist;
}

void Form::close()
{
    buttons.clear();
    for(auto i = textBoxes.begin(); i != textBoxes.end(); i++)
        (*i).clear();
    textBoxes.clear();
    labels.clear();

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

        manager.update(deltaTime);
    }
}

void Form::setCaption(std::string text)
{

}

void Form::createChars()
{
    EntityState::statsOfEntity stat;
    manager.initPlayer(EntityState::typeOfEntity::Amazon, sf::Vector2f(0,0), stat);
}

void Form::addChars(EntityState::typeOfEntity type, std::string nickname, sf::Vector2f position)
{
    manager.addEnemy(type, nickname, pos + position);
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
    std::cout << "Enter Form::add Label\n";
    sf::Text label;
    label.setCharacterSize(20);
    label.setFont(fontHolderMenu.get(fontID));
    label.setString(text);
    label.setPosition(position + pos);
    labels.push_back(label);
    std::cout << "add Label\n";
}

void Form::addButton(Forms::buttonID id, sf::Vector2f position, Textures::ID_InMenu texture_normal, Textures::ID_InMenu texture_pressed)
{
    Button button(id, texture_normal, texture_pressed, position + pos);
    buttons.push_back(button);
}

void Form::createForm(Forms::ID ID, Textures::ID_InMenu textureID, sf::Vector2f position)
{
    if(!labels.empty())
    labels.clear();
    if(!buttons.empty())
    buttons.clear();
    if(!textBoxes.empty())
    textBoxes.clear();

    isExsist = true;

    formSprite.setTexture(textureHolderMenu.get(textureID), true);

    formID = ID;

    sf::FloatRect rect = formSprite.getGlobalBounds();

    formSprite.setPosition(position);

    pos = position;
}

void Form::checkClick(sf::Vector2f cursorPosition)
{    
    manager.checkClick(cursorPosition);

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
                    {
                        sender.login(login, pass);
                    }

                }
                break;

            case Forms::buttonID::Register:
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
                {
                    sender.registerNew(login, pass);
                }
            }

                break;

            case Forms::buttonID::Play:
            {
                sender.sendChoosenChar(manager.getSeectedEnemy());
                gameState = States::Game;
            }
                break;

            case Forms::buttonID::New_Char:
            {
                if(formID == Forms::ID::ChooseCharacters)
                {
                    formID = Forms::ID::CreateNewChar;
                    for(buttonIterator = buttons.begin(); buttonIterator != buttons.end(); buttonIterator++)
                    {
                        pos = sf::Vector2f(400,500);
                        formSprite.setPosition(pos);
                        buttons.pop_back();
                        buttons.pop_back();
                        buttons.push_back(Button(Forms::buttonID::New_Char, Textures::LoginButton,
                                                 Textures::LoginButtonPressed, sf::Vector2f(pos.x + 10, pos.y + 80)));
                        buttons.push_back(Button(Forms::buttonID::Cancel, Textures::ExitButton,
                                                 Textures::ExitButtonPressed, sf::Vector2f(pos.x + 50, pos.y + 80)));

                    }

                }

                if(formID == Forms::ID::CreateNewChar)
                {
                    //sending new char request
                }
            }

                break;

            case Forms::buttonID::Cancel:
                {

                }

            break;
            }
        }
}
