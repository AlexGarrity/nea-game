#ifndef NETWORKMANAGER_H
#define NETWORKMANAGER_H

#include <SFML/Network.hpp>
#include "Debug.h"
#include <cstdio>

class NetworkManager
{
public:
    static void SendUDP(char message[64]);
    static void SendTCP(char message[64]);
    static void ReceiveUDP();
    static void ReceiveTCP();

    static void InitialiseSockets(const char* address, unsigned short tPort, unsigned short uPort);

    static void BindTCP(const char* address, unsigned short port);
    static void BindUDP(unsigned short port);

protected:

private:
    static sf::TcpSocket tcp;
    static sf::UdpSocket udp;

    static const char* serverAddress;
    static unsigned short UDPPort;
    static unsigned short TCPPort;
};

#endif // NETWORKMANAGER_H
