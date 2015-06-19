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
                        packet >> type;

                        id = static_cast<EntityState::typeOfEntity>(type);
                        std::cout << id << std::endl;

                        std::cout << "Char " << i+1 << " - " << nickname << " is type " << id << "\n";

                        mutex.lock();
                        application.menuPointer->formManager.form->addChars(id, nickname, sf::Vector2f(i*120 + 40, 200));
                        mutex.unlock();

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

                std::string nickname;

                sf::Vector2f position;

                packet >> nickname;

                packet >> type;

                packet >> position.x;
                packet >> position.y;

                EntityState::statsOfEntity stats;
                packet >> stats.attack >> stats.defence >> stats.hitPoints >> stats.manaPoints;

                std::cout << "Init player [parser.cpp]\n";

                std::cout << "Nickname:  " << nickname << "\n";
                while(application.gamePointer == nullptr)
                {

                }
                application.gamePointer->mWorld.initPlayer(static_cast<EntityState::typeOfEntity>(type), nickname, position, stats);
            }
            break;

            case NetworkCommands::AddEnemy:
            {
                std::cout << "Add enemy\n";
                std::string nick;
                packet >> nick;
                std::cout << "Enemy nick: " << nick;
                unsigned short type;
                packet >> type;

                std::cout << " type: " << type << "\n";
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
                application.gamePointer->mWorld.moveEnemy(nick, pos);
            }
                break;

            case NetworkCommands::DeleteChar:
            {

            }
                break;

            case NetworkCommands::NewChar:
            {
                bool isCreate;
                packet >> isCreate;
                if(isCreate)
                {

                    messenger.requestListOfUsers();
                }
            }
                break;

            case NetworkCommands::ExitGame:
            {

                std::string nick;
                packet >> nick;
                std::cout << "Nick in parser: " << nick << "\n";
                std::cout << "Enter delete enemy in parser\n";
                application.gamePointer->mWorld.deleteEnemy(nick);
            }
                break;

            case NetworkCommands::Attack:
            {
                std::cout << "Attack other enemy\n";
                std::string target, attacker;
                packet >> attacker >> target;
                std::cout << "Enemy " << attacker << " attacking " << target << "\n";
                application.gamePointer->mWorld.attackOtherEnemy(attacker, target);

            }
                break;

            case NetworkCommands::SetStats:
            {
                short att,def,hp,mana;
                sf::Vector2f pos;
                packet >> att;
                packet >> def;
                packet >> hp;
                packet >> mana;
                packet >> pos.x;
                packet >> pos.y;
                application.gamePointer->mWorld.entities.getPlayer()->setPosition(pos);
                application.gamePointer->mWorld.entities.getPlayer()->getStats()->manaPoints = mana;
                application.gamePointer->mWorld.entities.getPlayer()->getStats()->hitPoints = hp;
                application.gamePointer->mWorld.entities.getPlayer()->getStats()->attack = att;
                application.gamePointer->mWorld.entities.getPlayer()->getStats()->defence = def;

            }
                break;

            case NetworkCommands::Kill:
            {
                std::string killer, killed;
                packet >> killer;
                packet >> killed;
                sf::Vector2f pos = sf::Vector2f(3000,1250);
                application.gamePointer->mWorld.entities.findEnemy(killed)->setPosition(pos);
                application.gamePointer->mWorld.entities.setKillText(killer, killed);
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
