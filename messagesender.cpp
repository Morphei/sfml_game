#include "messagesender.h"


MessageSender::MessageSender()
{
}

void MessageSender::send(NetworkCommands::ID id, sf::Packet packet)
{
    sf::Packet normpacket;
    sendPort = 1234;
    normpacket << MARK << sendPort << NetworkCommands::ListOfUsers;
    netOperator.send(normpacket);
}

void MessageSender::login(std::string login, std::string pass)
{
    sf::Packet packet;
    sendPort = 1234;
    packet << MARK << sendPort << NetworkCommands::Login << login << pass;
    std::cout << sendPort << "\n";
    netOperator.send(packet);
}

void MessageSender::requestListOfUsers()
{
    sf::Packet packet;
    packet << MARK << sendPort << NetworkCommands::ListOfUsers;
    netOperator.send(packet);
}


