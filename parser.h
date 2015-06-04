#ifndef PARSER_H
#define PARSER_H

#include <SFML/Network.hpp>
#include <iostream>
#include "gamestates.h"
#include "networkoperator.h"
#include "application.h"
#include "messagesender.h"


class Parser
{
public:

    Parser();

    void run();
    void recieve();
    void stop();
    void startRecieve();

private:

    unsigned short sendPort;

    MessageSender messenger;

    Application application;
    NetworkOperator netOperator;
    NetworkCommands::ID command;
    sf::Thread recieveThread;
};

#endif // PARSER_H
