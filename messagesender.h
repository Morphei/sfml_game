#ifndef MESSAGESENDER_H
#define MESSAGESENDER_H

#include "networkoperator.h"
#include "networkconfiguration.h"
#include "gamestates.h"

class MessageSender
{
public:
    MessageSender();

    void send(NetworkCommands::ID id, sf::Packet packet);
    void requestListOfUsers();
    void login(std::string login, std::string pass);

private:
    unsigned short sendPort = 1234;
    NetworkCommands::ID command;
    NetworkOperator netOperator;
};

#endif // MESSAGESENDER_H
