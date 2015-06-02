#include "networkoperator.h"

NetworkOperator::NetworkOperator()
{

}

void NetworkOperator::connect()
{
    if (socket.bind(SERVER_PORT) != sf::Socket::Done)
    {
        throw std::runtime_error("Failed to bind");

    }
}

void NetworkOperator::send(sf::Packet packet)
{
    socket.send(packet, SERVER_IP, SERVER_PORT);
}

sf::Packet NetworkOperator::recieve()
{
        sf::Packet packet;

        if(socket.receive(packet, SERVER_IP, SERVER_PORT) == sf::Socket::Done)
        {
            return packet;
        }
}

