#include "parser.h"
#include "unistd.h"

Parser::Parser() : recieveThread(&Parser::recieve, this)
{
    netOperator = new NetworkOperator;
    XInitThreads();
}

void Parser::run()
{
    netOperator->bind();
    startRecieve();
    application.run();
    netOperator->unbind();
    stop();
}

void Parser::recieve()
{
    while(!stopRecieve)
        {
        sf::Packet packet = netOperator->recieve();

        unsigned short mark;

        packet >> mark;

        std::cout << "Mark: " << mark << " ";

        if(mark = MARK)
        {

            int temp;
            packet >> temp;
            command = static_cast<NetworkCommands::ID>(temp);
            std::cout << "Command " << command << "\n";
            switch (command) {

            case NetworkCommands::Login:
                {
                    std::cout << "Logining = " << command << "\n";
                    bool login;
                    packet >> login;
                    std::cout << "Is Login = " << login << "\n";
                    if(login)
                    {
                        std::cout << "Login OK" << std::endl;
                        messenger.requestListOfUsers();
                    }

                    else
                    {
                        std::cout << "NotLogin NeOK" << std::endl;
                    }
                }
            break;

            case NetworkCommands::ListOfUsers:
                {
                    int count;
                    unsigned short type;
                    std::string nickname;
                    EntityState::typeOfEntity id;

                    application.menuPointer->createChooseCharactersForm();

                    std::cout << "creating choose form\n";

                    packet >> count;
                    std::cout << count << " chars\n";

                    for(int i = 0; i < count; i++)
                    {
                        packet >> nickname;
                        std::cout << "Nickname: " << nickname << "\n";

                        mutex.lock();
                        application.menuPointer->formManager.form->addLabel(sf::Vector2f(i*120+10, 100), nickname, Fonts::MainFont);
                        mutex.unlock();

                        std::cout << nickname << " - ";

                        packet >> type;
                        id = static_cast<EntityState::typeOfEntity>(type);
                        std::cout << id << std::endl;

                        std::cout << "Char " << i+1 << " - " << nickname << " is type " << id << "\n";

                        application.menuPointer->formManager.form->addChars(id, nickname, sf::Vector2f(i*120 + 40, 200));

                        std::cout << "adding char\n";
                    }

                }
            break;

            case NetworkCommands::Register:
                {
//                    bool isRegister;
//                    packet >> isRegister;

//                    if(isRegister)
//                    {
//                        std::cout << "Register OK" << std::endl;
//                        messenger.requestListOfUsers();
//                        //menu->formManager.createForm(Forms::ChooseCharacters, 100, 100);
//                    }

//                    else
//                    {
//                        std::cout << "Register NeOK" << std::endl;
//                    }
                }

            break;

            case NetworkCommands::SendChoosenChar:
            {

                unsigned short type;
                packet >> type;

                sf::Vector2f position;
                packet >> position.x;
                packet >> position.y;

                EntityState::statsOfEntity stats;
                packet >> stats.attack >> stats.defence >> stats.hitPoints >> stats.manaPoints;

                std::cout << "Init player [parser.cpp]\n";

                while(application.gamePointer == nullptr)
                {

                }
                application.gamePointer->mWorld.initPlayer(static_cast<EntityState::typeOfEntity>(type), position, stats);
            }
            break;

            case NetworkCommands::AddEnemy:
            {
                std::cout << "Add enemy\n";
                std::string nick;
                packet >> nick;
                unsigned short type;
                packet >> type;
                sf::Vector2f pos;
                packet >> pos.x;
                packet >> pos.y;
                application.gamePointer->mWorld.addEnemy(nick, static_cast<EntityState::typeOfEntity>(type), pos);
            }

            break;

            case NetworkCommands::MouseClick:
            {
                std::string nick;
                sf::Vector2f pos;
                packet >> nick >> pos.x >> pos.y;
                std::cout << nick << " move to " << pos.x << ":" << pos.y << "\n";
                application.gamePointer->mWorld.moveEnemy(nick, pos);
            }
                break;

            case NetworkCommands::NewChar:
            {
                bool isCreate;
                packet >> isCreate;
                if(isCreate)
                    messenger.requestListOfUsers();
            }
                break;
            default:
                std::cout << "404\n";
            break;
            }
        }
        else std::cout << "MARK ne norm\n";

    }
    std::cout << "exit while\n";
//    recieveThread.terminate();
}

void Parser::stop()
{
    stopRecieve = true;
    exit(0);
}

void Parser::startRecieve()
{
    recieveThread.launch();
}
