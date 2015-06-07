#include <iostream>
#include "form.h"

Form::Form()
{

}

Form::~Form()
{
    isClosed = true;
    isExist = false;
}

bool Form::exsist()
{
    return isExist;
}

void Form::close()
{
    buttons.clear();
    for(auto i = textBoxes.begin(); i != textBoxes.end(); i++)
        (*i)->clear();
    textBoxes.clear();
    labels.clear();

}

void Form::processEvents(sf::Event event)
{
    for(auto i = textBoxes.begin(); i != textBoxes.end(); i++)
        if((*i)->isSelected())
            (*i)->processEvents(event);
}

void Form::update(sf::Time deltaTime)
{
    if(isClosed)
        isExist = false;
    else
    {
        for(auto i = textBoxes.begin(); i != textBoxes.end(); i++)
            (*i)->update(deltaTime);
        for(auto i = buttons.begin(); i != buttons.end(); i++)
            (*i)->update();

        manager.update(deltaTime);
    }
}

void Form::setCaption(std::string text)
{

}

void Form::isCreated()
{
    isExist = true;
}

std::string Form::getTextBoxText(Forms::textBoxID id)
{
    std::string text;
    bool isEmpty = true;

    for(std::vector<TextBox*>::iterator j = textBoxes.begin(); j != textBoxes.end(); j++)
    {

        if((*j)->getName() == id)
        {
            text = (*j)->getText();
            isEmpty = true;
            if(text.size() == 0)
                isEmpty = true;
        }
    }

    if(!isEmpty)
    {
        return text;
    }

}

void Form::createChars()
{
    EntityState::statsOfEntity stat;
    manager.initPlayer(EntityState::typeOfEntity::Amazon, sf::Vector2f(0,0), stat);
    std::cout << "Form::createChars()\n";
}

void Form::addChars(EntityState::typeOfEntity type, std::string nickname, sf::Vector2f position)
{
    std::cout << "Form::addChar()\n";
    manager.addEnemy(type, nickname, pos + position);
}

void Form::addTextBox(Forms::textBoxID boxName ,sf::Vector2f position, Fonts::ID_InMenu id, bool enableMask)
{
    std::cout << "Enter Form::add TextBox\n";
    TextBox* box = new TextBox;

    box->init(boxName ,pos + position, id);
    box->enableMask(enableMask);
//    isExist = true;
    textBoxes.push_back(box);
    std::cout << "add addTextBox\n";
}



void Form::addLabel(sf::Vector2f position, std::string text, Fonts::ID_InMenu fontID)
{
    std::cout << "Enter Form::add Label\n";
    sf::Text* label = new sf::Text;
    label->setCharacterSize(20);
    label->setFont(fontHolderMenu.get(fontID));
    label->setString(text);
    label->setPosition(position + pos);
    labels.push_back(label);
    std::cout << "add Label\n";
}

void Form::addButton(Forms::buttonID id, std::string caption, sf::Vector2f position, Textures::ID_InMenu texture_normal, Textures::ID_InMenu texture_pressed)
{
    std::cout << "Before new Button in Form::addButton\n";
    Button* button = new Button(id, texture_normal, texture_pressed, caption, position + pos);
    std::cout << "Pusging button to buttons\n";
    buttons.push_back(button);
    std::cout << "pushed\n";

}

void Form::createForm(Forms::ID ID, Textures::ID_InMenu textureID, sf::Vector2f position)
{
//    if(!labels.empty())
//    labels.clear();
//    if(!buttons.empty())
//    buttons.clear();
//    if(!textBoxes.empty())
//    textBoxes.clear();


    formSprite.setTexture(textureHolderMenu.get(textureID), true);

    formID = ID;

    sf::FloatRect rect = formSprite.getGlobalBounds();

    formSprite.setPosition(position);

    pos = position;

//    isExsist = true;

    std::cout << "Form is created succesfuly\n";

}

Forms::buttonID Form::checkClick(sf::Vector2f cursorPosition)
{    
    manager.checkClick(cursorPosition);

    for(auto i = textBoxes.begin(); i != textBoxes.end(); i++)
        (*i)->checkClick(cursorPosition);

    for(auto i = buttons.begin(); i != buttons.end(); i++)
        if((*i)->checkClick(cursorPosition))
        {
            return((*i)->getID());
        }
}
