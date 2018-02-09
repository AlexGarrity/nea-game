/**     Alex Garrity, 2018      **/

#ifndef NETWORKMANAGER_H
#define NETWORKMANAGER_H

#include <queue>
#include <string>
#include <cstring>

#include <SFML/Network.hpp>

#include "Debug.h"
#include "Settings.h"
#include "Crypto.h"

struct NetworkInstruction
{
public:
    unsigned char type;
    char subject[16];
    std::string details;
    NetworkInstruction (unsigned char t, char *s, std::string d)
    {
        type = t;
        std::strcpy(subject, s);
        details = d;
    }
};

class NetworkManager
{
public:
    static void InitialiseSockets (sf::IpAddress ipAddress, unsigned short tcpPort, unsigned short udpPort);
    static void Update();
    static void EndConnection();
    static void Login (std::string username, std::string password);

    static std::queue <NetworkInstruction> updateQueueDown;
    static std::queue <NetworkInstruction> updateQueueUp;

protected:

private:
    static void GetUpdates();
    static void ProcessUpdates();
    static void PushUpdates();
    static void ClearQueues();
    static void ChangeServer();

    static sf::TcpSocket tcpSocket;
    static sf::UdpSocket udpSocket;

    static sf::Packet tcpDownPacket;
    static sf::Packet udpDownPacket;
    static sf::Packet tcpUpPacket;
    static sf::Packet udpUpPacket;
};

#endif // NETWORKMANAGER_H
