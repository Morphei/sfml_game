#ifndef FORM_H
#define FORM_H

#include <SFML/Graphics.hpp>
#include "form.h"
#include "gamestates.h"
#include "resourcemanager.h"
#include "button.h"
#include "textbox.h"
#include "messagesender.h"


class Form : public sf::Drawable
{
public:
    Form();

    bool exsist();
    void processEvents(sf::Event event);
    void createForm(Textures::ID_InMenu id, sf::Vector2f position);
    void update(sf::Time deltaTime);
    void setCaption(std::string text);

    void addTextBox(Forms::textBoxID boxName ,sf::Vector2f position, Fonts::ID_InMenu id, bool enableMask);
    void addLabel(sf::Vector2f position, std::string text, Fonts::ID_InMenu fontID);
    void addButton(Forms::buttonID id, sf::Vector2f position, Textures::ID_InMenu id_normal, Textures::ID_InMenu id_pressed);

    void checkClick(sf::Vector2f cursorPosition);

private:
    MessageSender sender;

    bool isExsist = false;
    bool isClosed = false;

    sf::Vector2f pos;

    std::vector<sf::Text> labels;
    std::vector<TextBox>::iterator boxIterator;
    std::vector<TextBox> textBoxes;
    std::vector<Button> buttons;

    sf::Sprite formSprite;

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
            target.draw(formSprite);
            for(auto i = labels.begin(); i != labels.end(); i++)
                target.draw(*i);
            for(auto i = textBoxes.begin(); i != textBoxes.end(); i++)
                target.draw(*i);
            for(auto i = buttons.begin(); i != buttons.end(); i++)
                target.draw(*i);
    }


};



#endif // FORM_H
