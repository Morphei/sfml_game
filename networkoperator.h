#ifndef NETWORKOPERATOR_H
#define NETWORKOPERATOR_H

#include "iostream"

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
    bool started();


private:

    sf::IpAddress ip;
    unsigned short port;

    bool isStarted = true;
    sf::UdpSocket socket;
    sf::Mutex mutex;




};

#endif // NETWORKOPERATOR_H
