#include "parser.h"

Parser::Parser(Menu *owner) : recieveThread(&Parser::recieve, this)
{
    menu = owner;
    sendPort = 1234;
    std::cout << sendPort << "\n";
}

//Parser::Parser(Game *owner) : recieveThread(&Parser::recieve, this)
//{
//    game = owner;
//}

void Parser::requestListOfUsers()
{
    sf::Packet normpacket;
    sendPort = 1234;
    normpacket << MARK << sendPort << Commands::ListOfUsers;
    netOperator.send(normpacket);
}

void Parser::login(std::string login, std::string pass)
{
    sf::Packet packet;
    sendPort = 1234;
    packet << MARK << sendPort << Commands::Login << login << pass;
    std::cout << sendPort << "\n";
    netOperator.send(packet);
}

void Parser::recieve()
{
    while(true)
        {
        sf::Packet packet = netOperator.recieve();

        unsigned short mark;

        packet >> mark;

        if(mark = MARK)
        {

            int temp;
            packet >> temp;
            std::cout << "Parsing command from temp[" << temp << "]\n";
            command = static_cast<Commands::ID>(temp);
            std::cout << "Packet with command " << command << "\n";
            switch (command) {

            case Commands::Login:
                {
                    bool isLogin;
                    packet >> isLogin;

                    if(isLogin)
                    {
                        std::cout << "Login OK" << std::endl;
//                        requestListOfUsers();
                        //menu->formManager.createForm(Forms::ChooseCharacters, 100, 100);
                    }

                    else
                    {
                        std::cout << "NotLogin NeOK" << std::endl;
                    }
                }
            break;

            case Commands::ListOfUsers:
                {
                    int count;
                    std::string nickname;
                    packet >> count;
                    std::cout << "You have " << count << " charachters, which is: " << std::endl;
                    for(int i = 0; i < count; i++)
                    {
                        packet >> nickname;
                        std::cout << nickname << std::endl;
                    }
                }
            break;

            case Commands::Register:
                {

                }

            break;

            default:
                std::cout << "404\n";
            break;
            }
        }
        else std::cout << "MARK ne norm\n";

    }
}

void Parser::stop()
{
    recieveThread.terminate();
}

void Parser::startRecieve()
{
    recieveThread.launch();
}
