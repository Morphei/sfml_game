#include "menu.h"


Menu::Menu() : mWindow(sf::VideoMode(1366,768), "Arms Race", sf::Style::Fullscreen)
{

    Button but(Textures::LoginButton, Textures::LoginButtonPressed, 100, 600);
    Button but3(Textures::RegisterButton, Textures::RegisterButtonPressed, 100, 550);
    Button but2(Textures::ExitButton, Textures::ExitButtonPressed, 100, 650);

    buttons.insert(std::pair<buttonID, Button> (buttonID::Login, but));
    buttons.insert(std::pair<buttonID, Button> (buttonID::Register, but3));
    buttons.insert(std::pair<buttonID, Button> (buttonID::Exit, but2));

    background.setTexture(textureHolderMenu.get(Textures::MenuBackground));

}

void Menu::run()
{
//    parser = new Parser(this);
//    parser->initNetwork();
//    parser->startRecieve();
//    parser->login("morphei","mor123");


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
}

void Menu::login()
{
    form = formManager.createForm(Forms::Login, sf::Vector2f(1000,400));
}

void Menu::registerPlayer()
{
    form = formManager.createForm(Forms::Register, sf::Vector2f(1000,10));
}

void Menu::render()
{
    mWindow.clear();
    mWindow.draw(background);

    for(itr = buttons.begin(); itr!= buttons.end(); itr++)
    {
        mWindow.draw((*itr).second);
    }

    if(form.exsist())
    mWindow.draw(form);

    mWindow.display();
}

void Menu::update(sf::Time deltaTime)
{
    for(itr = buttons.begin(); itr!= buttons.end(); itr++)
    {
            (*itr).second.update();
    }

    if(form.exsist())
    form.update(deltaTime);
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
                        if((*itr).second.checkClick(cursorPosition))
                        {
                                    switch ((*itr).first) {
                                    case buttonID::Login:
                                           login();
                                        break;

                                    case buttonID::Register:
                                            registerPlayer();
                                        break;

                                    case buttonID::Settings:

                                        break;

                                    case buttonID::Exit:
                                            exit();
                                        break;

                                }
                        }
                    }

                    form.checkClick(cursorPosition);
            }

            if(event.type == sf::Event::TextEntered)
                form.processEvents(event);

        }


}

void Menu::startNew()
{
    //parser->stop();
    gameState = States::Game;
    mWindow.close();
}

void Menu::exit()
{
    //parser->stop();
    gameState = States::Close;
    mWindow.close();
}
