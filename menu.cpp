#include "menu.h"


Menu::Menu() : mWindow(sf::VideoMode(1366,768), "Arms Race", sf::Style::Fullscreen)
{


}

Player Menu::run()
{
    Button but2(Forms::buttonID::Exit, Textures::ExitButton, Textures::ExitButtonPressed, sf::Vector2f(100, 650));

    buttons.push_back(but2);

    background.setTexture(textureHolderMenu.get(Textures::MenuBackground));

    createLoginForm();
//    createChooseCharactersForm();

    sf::Clock mainClock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;

    while(mWindow.isOpen())
         {
            processEvents();
            timeSinceLastUpdate += mainClock.restart();

            while(timeSinceLastUpdate > TimePerFrame)
                {
                    timeSinceLastUpdate -= TimePerFrame;
                    processEvents();
                    update(TimePerFrame);
                }

            render();
    }
    return player;
}

void Menu::render()
{
    mWindow.clear();
    mWindow.draw(background);

    for(itr = buttons.begin(); itr!= buttons.end(); itr++)
    {
        mWindow.draw((*itr));
    }

    if(form->exsist())
    mWindow.draw(*form);

    mWindow.display();
}

void Menu::update(sf::Time deltaTime)
{
    if(gameState!= States::Menu)
    {
        mWindow.close();
    }
    for(itr = buttons.begin(); itr!= buttons.end(); itr++)
    {
            (*itr).update();
    }

    if(form->exsist())
    form->update(deltaTime);
}

void Menu::processEvents()
{

    sf::Event event;

    while (mWindow.pollEvent(event))
        {

            if(event.type == sf::Event::Closed)
            {
                gameState = States::Close;
                mWindow.close();
            }

            if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                    pixelPos = sf::Mouse::getPosition(mWindow);
                    cursorPosition = mWindow.mapPixelToCoords(pixelPos);

                    for(itr = buttons.begin(); itr != buttons.end(); itr++)
                    {
                        if((*itr).checkClick(cursorPosition))
                        {
                                    switch ((*itr).getID()) {
                                    case Forms::buttonID::Login:

                                        break;

                                    case Forms::buttonID::Register:

                                        break;

                                    case Forms::buttonID::Settings:

                                        break;

                                    case Forms::buttonID::Exit:
                                            exit();
                                        break;

                                }
                        }
                    }

                    form->checkClick(cursorPosition);
            }

            if(event.type == sf::Event::TextEntered)
                form->processEvents(event);

        }


}

void Menu::createLoginForm()
{
    form = formManager.createForm(Forms::LoginForm, sf::Vector2f(1100,50));
}

void Menu::createChooseCharactersForm()
{
    form = formManager.createForm(Forms::ChooseCharacters, sf::Vector2f(300, 50));
}

void Menu::startNew()
{
    gameState = States::Game;
    mWindow.close();
}

void Menu::initPlayer(EntityState::typeOfEntity id, sf::Vector2f position, EntityState::statsOfEntity stats)
{
    player.setPosition(position);
    player.setStats(stats);
    player.setType(id);
}

void Menu::exit()
{
    form->close();
    gameState = States::Close;
    mWindow.close();
}

void Menu::close()
{
    form->close();
    mWindow.close();
}