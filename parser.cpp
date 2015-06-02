#include "parser.h"

Parser::Parser(Menu *owner) : recieveThread(&Parser::recieve, this)
{
    menu = owner;
}

Parser::Parser(Game *owner) : recieveThread(&Parser::recieve, this)
{
    game = owner;
}

void Parser::requestListOfUsers()
{
    sf::Packet normpacket;
    normpacket << MARK << Commands::ListOfUsers;
    netOperator.send(normpacket);
    std::cout << "Sending packet" << std::endl;
}

void Parser::login(std::string login, std::string pass)
{
    sf::Packet packet;
    packet << MARK << Commands::Login << login << pass;
    netOperator.send(packet);
}

void Parser::initNetwork()
{
    netOperator.connect();
}

void Parser::recieve()
{
    sf::Packet packet = netOperator.recieve();

    int mark;

    packet >> mark;

    if(mark = MARK)
    {

        int temp;
        packet >> temp;
        command = static_cast<Commands::ID>(temp);

        switch (command) {
        case Commands::Login:
            {
                bool isLogin;
                packet >> isLogin;

                if(isLogin)
                {
                    std::cout << "Login OK" << std::endl;//TODO: Create login in menu

                }

                else
                {
                    std::cout << "NotLogin NeOK" << std::endl;//TODO: Create login in menu
                }
            }

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
        }
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
