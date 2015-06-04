#include "parser.h"

Parser::Parser() : recieveThread(&Parser::recieve, this)
{
    sendPort = 1234;
    std::cout << sendPort << "\n";
}

void Parser::run()
{
    netOperator.bind();
    startRecieve();
    application.run();
    stop();
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
            command = static_cast<NetworkCommands::ID>(temp);
            std::cout << "Packet with command " << command << "\n";
            switch (command) {

            case NetworkCommands::Login:
                {
                    bool isLogin;
                    packet >> isLogin;

                    if(isLogin)
                    {
                        std::cout << "Login OK" << std::endl;
                        messenger.requestListOfUsers();
                        //menu->formManager.createForm(Forms::ChooseCharacters, 100, 100);
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

            case NetworkCommands::Register:
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
