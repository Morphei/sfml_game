#ifndef NETWORKOPERATOR_H
#define NETWORKOPERATOR_H

#include <SFML/Network.hpp>
#include "networkconfiguration.h"

//          TODO List
//  1. Парсинг пакетів із сервера
//  2. реалізація методу send()
//
//
//
//

class NetworkOperator
{
public:
    NetworkOperator();
    void connect();
    void send(sf::Packet packet);
    sf::Packet recieve();

private:

    sf::UdpSocket socket;


};

#endif // NETWORKOPERATOR_H
