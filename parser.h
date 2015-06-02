#ifndef PARSER_H
#define PARSER_H

namespace Commands{
        enum ID {
                Login,
                ListOfUsers,
                Register
                };
    }

#include <SFML/Network.hpp>
#include <iostream>
#include "networkoperator.h"
//#include "networkconfiguration.h"

class Game;
class Menu;

class Parser
{
public:
    Parser(Menu *owner);
    Parser(Game *owner);
    void requestListOfUsers();
    void login(std::string login, std::string pass);
    void initNetwork();
    void send(Commands::ID id, sf::Packet packet);
    void recieve();
    void stop();
    void startRecieve();

private:
    Menu *menu = NULL;
    Game *game = NULL;
    NetworkOperator netOperator;
    Commands::ID command;
    sf::Thread recieveThread;
};

#endif // PARSER_H
