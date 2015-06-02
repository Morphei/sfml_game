#include "formmanager.h"

FormManager::FormManager()
{
}

Form FormManager::createForm(Forms::ID id, sf::Vector2f position)
{
    Form form;
    switch (id) {
    case Forms::Login:
        {
            form.createForm(Textures::LoginForm, position);
            form.setCaption("Login");

            form.addLabel(sf::Vector2f(20, 70), "Login", Fonts::MainFont);
            form.addTextBox(sf::Vector2f(20, 110), Fonts::MainFont);

            form.addLabel(sf::Vector2f(20, 170), "Password", Fonts::MainFont);
            form.addTextBox(sf::Vector2f(20, 210), Fonts::MainFont);


        }

        break;

    case Forms::Register:
        {
            form.createForm(Textures::RegisterForm, position);
            form.setCaption("New Player");

            form.addLabel(sf::Vector2f(20, 70), "Login", Fonts::MainFont);
            form.addTextBox(sf::Vector2f(20, 110), Fonts::MainFont);

            form.addLabel(sf::Vector2f(20, 170), "Password", Fonts::MainFont);
            form.addTextBox(sf::Vector2f(20, 210), Fonts::MainFont);
        }
        break;
    }

    return form;
}
