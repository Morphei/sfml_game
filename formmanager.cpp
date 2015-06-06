#include "formmanager.h"

FormManager::FormManager()
{
}

Form* FormManager::createForm(Forms::ID id, sf::Vector2f position)
{
    switch (id) {
    case Forms::LoginForm:
        {
            form.createForm(id, Textures::LoginForm, position);
            form.setCaption("Login");

            form.addLabel(sf::Vector2f(20, 70), "Login", Fonts::MainFont);
            form.addTextBox(Forms::textBoxID::LoginTextBox, sf::Vector2f(20, 110), Fonts::MainFont, false);

            form.addLabel(sf::Vector2f(20, 150), "Password", Fonts::MainFont);
            form.addTextBox(Forms::textBoxID::PasswordTextBox, sf::Vector2f(20, 190), Fonts::MainFont, true);


            form.addButton(Forms::buttonID::Login, sf::Vector2f(10,250), Textures::LoginButton, Textures::LoginButtonPressed);
            form.addButton(Forms::buttonID::Register, sf::Vector2f(90,250), Textures::RegisterButton, Textures::RegisterButtonPressed);
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

    case Forms::ChooseCharacters:
        {
            form.createForm(Forms::ID::ChooseCharacters ,Textures::ChooseForm, position);

            form.createChars();
            form.addButton(Forms::buttonID::Play, sf::Vector2f(10, 100), Textures::LoginButton, Textures::LoginButtonPressed);
            form.addButton(Forms::buttonID::New_Char, sf::Vector2f(100, 100), Textures::LoginButton, Textures::LoginButtonPressed);
        }
    break;
    }

    return &form;
}
