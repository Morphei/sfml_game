#include "messagesender.h"


MessageSender::MessageSender()
{
}

void MessageSender::bind()
{
    netOperator.bind();
}

void MessageSender::unbind()
{
    netOperator.unbind();
}

void MessageSender::attackEnemy(std::string name)
{
    sf::Packet packet;
    packet << MARK << LOCAL_PORT << NetworkCommands::Attack << name;
    netOperator.send(packet);
    std::cout << "MessageSender::Attack\n";
}

void MessageSender::sendCharToDelete(std::string nickname)
{
    sf::Packet packet;
    packet << MARK << LOCAL_PORT << NetworkCommands::DeleteChar << nickname;
    netOperator.send(packet);
    std::cout << "MessageSender::Deleting\n";
}

void MessageSender::sendCreateNewChar(std::string nickname, EntityState::typeOfEntity type)
{
    sf::Packet packet;
    packet << MARK << LOCAL_PORT << NetworkCommands::NewChar << nickname << type;
    netOperator.send(packet);
    std::cout << "MessageSender::SendingNewChar\n";
}

void MessageSender::exitGame()
{
    sf::Packet packet;
    packet << MARK << LOCAL_PORT << NetworkCommands::ExitGame;
    netOperator.send(packet);
    std::cout << "MessageSender::ExitGame\n";
}

void MessageSender::sendMouseClick(sf::Vector2f pos)
{
    sf::Packet packet;
    packet << MARK << LOCAL_PORT << NetworkCommands::MouseClick << pos.x << pos.y;
    netOperator.send(packet);
    std::cout << "Vector: " << pos.x << ":" << pos.y << "\n";
    std::cout << "MessageSender::MouseClick\n";
}

void MessageSender::inGame()
{
    sf::Packet packet;
    bool ok = true;
    packet << MARK << LOCAL_PORT << NetworkCommands::InGame << ok;
    netOperator.send(packet);
    std::cout << "MessageSender::InGame\n";
}

void MessageSender::send(NetworkCommands::ID id, sf::Packet packet)
{
    sf::Packet normpacket;
    normpacket << MARK << LOCAL_PORT << NetworkCommands::ListOfUsers;
    netOperator.send(normpacket);
}

void MessageSender::login(std::string login, std::string pass)
{
    std::cout << "MessageSender::Login\n";
    sf::Packet packet;

    packet << MARK;
    packet << LOCAL_PORT;
    packet << NetworkCommands::Login;
    packet << login;
    packet << pass;

    netOperator.send(packet);

}

void MessageSender::registerNew(std::string login, std::string pass)
{
    sf::Packet packet;
    packet << MARK << LOCAL_PORT << NetworkCommands::Register << login << pass;
    netOperator.send(packet);
    std::cout << "MessageSender::Register\n";
}

void MessageSender::sendChoosenChar(std::string id)
{
    sf::Packet packet;

    packet << MARK << LOCAL_PORT << NetworkCommands::SendChoosenChar << id;
    netOperator.send(packet);
    std::cout << "MessageSender::Sending Player's Choosen Char\n";
}

void MessageSender::requestListOfUsers()
{
    sf::Packet packet;
    packet << MARK << LOCAL_PORT << NetworkCommands::ListOfUsers;
    netOperator.send(packet);
    std::cout << "MessageSender::Requesting list of chars\n";
}


