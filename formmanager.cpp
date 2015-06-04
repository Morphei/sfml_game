#include "formmanager.h"

FormManager::FormManager()
{
}

Form FormManager::createForm(Forms::ID id, sf::Vector2f position)
{
    Form form;
    switch (id) {
    case Forms::LoginForm:
        {
            form.createForm(Textures::LoginForm, position, menuParser);
            form.setCaption("Login");

            form.addLabel(sf::Vector2f(20, 70), "Login", Fonts::MainFont);
            form.addTextBox(Forms::textBoxID::LoginTextBox, sf::Vector2f(20, 110), Fonts::MainFont, false);

            form.addLabel(sf::Vector2f(20, 170), "Password", Fonts::MainFont);
            form.addTextBox(Forms::textBoxID::PasswordTextBox, sf::Vector2f(20, 210), Fonts::MainFont, true);


            form.addButton(Forms::buttonID::Login, sf::Vector2f(50,250), Textures::LoginButton, Textures::LoginButtonPressed);
        }

        break;

    case Forms::RegisterForm:
        {
//            form.createForm(Textures::RegisterForm, position, menuParser);
//            form.setCaption("New Player");

//            form.addLabel(sf::Vector2f(20, 70), "Login", Fonts::MainFont);
//            form.addTextBox(sf::Vector2f(20, 110), Fonts::MainFont, false);

//            form.addLabel(sf::Vector2f(20, 170), "Password", Fonts::MainFont);
//            form.addTextBox(sf::Vector2f(20, 210), Fonts::MainFont, true);
        }
        break;
    }

    return form;
}

void FormManager::setParser(Parser *parser)
{
    menuParser = parser;
}
