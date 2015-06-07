#ifndef FORMMANAGER_H
#define FORMMANAGER_H

#include "gamestates.h"
#include "SFML/Graphics.hpp"
#include "form.h"


class FormManager : public sf::Drawable
{
public:
    FormManager();

    void createForm(Forms::ID id, sf::Vector2f position);

    void checkClick(sf::Vector2f mousePos);

    void update(sf::Time deltaTime);

    void processEvents(sf::Event event);

    void close();

    Form* form;

private:
    bool ready = false;

    MessageSender sender;

    void draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        if(ready)
        target.draw(*form, states);
    }
};

#endif // FORMMANAGER_H
