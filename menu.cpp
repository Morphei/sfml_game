#include "menu.h"


Menu::Menu() : mWindow(sf::VideoMode(1366,768), "Arms Race", sf::Style::Fullscreen)
{

    Button but2(Forms::buttonID::Exit, Textures::ExitButton, Textures::ExitButtonPressed, sf::Vector2f(100, 650));

    buttons.push_back(but2);

    background.setTexture(textureHolderMenu.get(Textures::MenuBackground));

    login();

    parser = new Parser(this);

    formManager.setParser(parser);

}

void Menu::run()
{
    parser->startRecieve();

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
//    std::cout << "EnterLogin" << std::endl;
////    startNew();
//    parser->login("morphei","mor123");
    form = formManager.createForm(Forms::LoginForm, sf::Vector2f(1100,50));
}

void Menu::registerPlayer()
{
    //form = formManager.createForm(Forms::Register, sf::Vector2f(1000,10));
}

void Menu::render()
{
    mWindow.clear();
    mWindow.draw(background);

    for(itr = buttons.begin(); itr!= buttons.end(); itr++)
    {
        mWindow.draw((*itr));
    }

    if(form.exsist())
    mWindow.draw(form);

    mWindow.display();
}

void Menu::update(sf::Time deltaTime)
{
    for(itr = buttons.begin(); itr!= buttons.end(); itr++)
    {
            (*itr).update();
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
                        if((*itr).checkClick(cursorPosition))
                        {
                                    switch ((*itr).getID()) {
                                    case Forms::buttonID::Login:
                                           login();
                                        break;

                                    case Forms::buttonID::Register:
                                            registerPlayer();
                                        break;

                                    case Forms::buttonID::Settings:

                                        break;

                                    case Forms::buttonID::Exit:
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
