#ifndef PARSER_H
#define PARSER_H

#include <SFML/Network.hpp>
#include <iostream>
#include "gamestates.h"
#include "networkoperator.h"
#include "application.h"
#include "messagesender.h"
#include "form.h"



//TODO - segfault after thread.terminate()

class Parser
{
public:

    Parser();

    void run();

    void recieve();
    void stop();
    void startRecieve();

private:
    bool stopRecieve = false;

    sf::Mutex mutex;

    MessageSender messenger;

    Application application;
    NetworkOperator* netOperator;
    NetworkCommands::ID command;
    sf::Thread recieveThread;
};

#endif // PARSER_H
