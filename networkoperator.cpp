#include "networkoperator.h"

NetworkOperator::NetworkOperator()
{

}

void NetworkOperator::bind()
{
    if (socket.bind(sf::Socket::AnyPort) != sf::Socket::Done)
    {
        throw std::runtime_error("Failed to bind");
    }
    LOCAL_PORT = socket.getLocalPort();
    std::cout << "Local port is " << LOCAL_PORT << "\n";
}

void NetworkOperator::unbind()
{
    socket.unbind();
}

void NetworkOperator::send(sf::Packet packet)
{

    sf::UdpSocket sendSocket;

    sendSocket.send(packet, SERVER_IP, SERVER_PORT);

}

sf::Packet NetworkOperator::recieve()
{
        sf::Packet packet;

        if(socket.receive(packet, ip, port) == sf::Socket::Done)
        {

            return packet;
        }
}

