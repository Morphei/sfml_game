#include "formmanager.h"

FormManager::FormManager()
{
}

void FormManager::createForm(Forms::ID id, sf::Vector2f position)
{
    ready = false;

    form = new Form;

    switch (id) {
    case Forms::LoginForm:
        {
            form->createForm(id, Textures::LoginForm, position);
            form->setCaption("Login");

            form->addLabel(sf::Vector2f(20, 70), "Login", Fonts::MainFontMenu);
            form->addTextBox(Forms::textBoxID::LoginTextBox, sf::Vector2f(20, 110), Fonts::MainFontMenu, false);

            form->addLabel(sf::Vector2f(20, 150), "Password", Fonts::MainFontMenu);
            form->addTextBox(Forms::textBoxID::PasswordTextBox, sf::Vector2f(20, 190), Fonts::MainFontMenu, true);


            form->addButton(Forms::buttonID::Login, "Login" ,sf::Vector2f(10,250), Textures::Button, Textures::ButtonPressed);
            form->addButton(Forms::buttonID::Register, "Register", sf::Vector2f(90,250), Textures::Button, Textures::ButtonPressed);

            form->isCreated();

            ready = true;
        }

        break;

    case Forms::RegisterForm:
        {
            form->createForm(Forms::ID::RegisterForm, Textures::RegisterForm, position);
            form->setCaption("New Player");

            form->addLabel(sf::Vector2f(20, 70), "Login", Fonts::MainFontMenu);
            form->addTextBox(Forms::textBoxID::LoginTextBox, sf::Vector2f(20, 110), Fonts::MainFontMenu, false);

            form->addLabel(sf::Vector2f(20, 170), "Password", Fonts::MainFontMenu);
            form->addTextBox(Forms::textBoxID::PasswordTextBox, sf::Vector2f(20, 210), Fonts::MainFontMenu, true);

            form->isCreated();
        }
        break;

    case Forms::ChooseCharacters:
        {


            form->createForm(Forms::ID::ChooseCharacters ,Textures::ChooseForm, position);

            form->createChars();

            std::cout << "Exit Formmanager::create chars to ChCharForm\n";
            form->addButton(Forms::buttonID::Play, "Play", sf::Vector2f(10, 200), Textures::Button, Textures::ButtonPressed);
            std::cout << "pushed play button\n";
            form->addButton(Forms::buttonID::New_Char, "Create Char", sf::Vector2f(120, 200), Textures::Button, Textures::ButtonPressed);
            std::cout << "pushed create char button\n";
            form->addButton(Forms::buttonID::Delete_char, "Delete Char", sf::Vector2f(270, 200), Textures::Button, Textures::ButtonPressed);
            std::cout << "FormManager::create buttons to ChooseCharacters\n";

            form->isCreated();

            ready = true;

          }
          break;

    case Forms::CreateNewChar:
        {
            form->createForm(Forms::ID::CreateNewChar, Textures::ChooseForm, position);

            form->addButton(Forms::buttonID::CreateNew, "Create Char", sf::Vector2f(250, 200), Textures::Button, Textures::ButtonPressed);
            form->addTextBox(Forms::textBoxID::LoginTextBox, sf::Vector2f(40, 200), Fonts::MainFontMenu, false);

            form->addLabel(sf::Vector2f(40, 170), "Enter your nickname", Fonts::MainFontMenu);

            form->createChars();

            form->manager.addEnemy(EntityState::Amazon, "Amazon", sf::Vector2f(position.x + 100, position.y + 160));
            form->manager.addEnemy(EntityState::Paladin, "Paladin", sf::Vector2f(position.x + 200, position.y + 160));

            form->isCreated();

            ready = true;
        }
        break;
}
}

void FormManager::checkClick(sf::Vector2f mousePos)
{
    Forms::buttonID id = form->checkClick(mousePos);
                switch (id) {
                case Forms::buttonID::Login:
                    {
                        std::string login, pass;
                        login = form->getTextBoxText(Forms::textBoxID::LoginTextBox);
                        pass = form->getTextBoxText(Forms::textBoxID::PasswordTextBox);
                        sender.login(login,pass);
                    }
                    break;

                case Forms::buttonID::Register:
                    {
                        std::string login, pass;
                        login = form->getTextBoxText(Forms::textBoxID::LoginTextBox);
                        pass = form->getTextBoxText(Forms::textBoxID::PasswordTextBox);
                        sender.registerNew(login, pass);
                    }

                    break;

                case Forms::buttonID::Play:
                {
                    sender.sendChoosenChar(form->manager.getSeectedEnemy());
                    gameState = States::Game;
                }
                    break;

                case Forms::buttonID::New_Char:
                {
                    createForm(Forms::ID::CreateNewChar, sf::Vector2f(100, 100));
                }

                    break;

                case Forms::buttonID::CreateNew:
                {
                    std::string nickname = form->getTextBoxText(Forms::textBoxID::LoginTextBox);
                    EntityState::typeOfEntity type = form->manager.getSelectedEnemyType();
                    sender.sendCreateNewChar(nickname, type);
                }
                    break;

                case Forms::buttonID::Delete_char:
                {
                    std::string nickname = form->manager.getSeectedEnemy();
                    EntityState::typeOfEntity type = form->manager.getSelectedEnemyType();

                    sender.sendCharToDelete(nickname, type);
                }
                    break;

                case Forms::buttonID::Cancel:
                    {

                    }

                break;
                }

}

void FormManager::update(sf::Time deltaTime)
{
    if(form->exsist())
        form->update(deltaTime);
}

void FormManager::processEvents(sf::Event event)
{
    if(form->exsist())
        form->processEvents(event);
}

void FormManager::close()
{
    form->close();
//    delete form;
}

