#ifndef MESSAGESENDER_H
#define MESSAGESENDER_H

#include "networkoperator.h"
#include "networkconfiguration.h"
#include "gamestates.h"

class MessageSender
{
public:
    MessageSender();

    void sendCharToDelete(std::string nickname, EntityState::typeOfEntity type);
    void sendCreateNewChar(std::string nickname, EntityState::typeOfEntity type);
    void exitGame();
    void sendMouseClick(sf::Vector2f pos);
    void inGame();
    void send(NetworkCommands::ID id, sf::Packet packet);
    void requestListOfUsers();
    void login(std::string login, std::string pass);
    void registerNew(std::string login, std::string pass);
    void sendChoosenChar(std::string id);

private:
//    unsigned short sendPort = LOCAL_PORT;
    NetworkCommands::ID command;
    NetworkOperator netOperator;
};

#endif // MESSAGESENDER_H
