/**     Alex Garrity, 2018      **/

#ifndef NETWORKMANAGER_H
#define NETWORKMANAGER_H

#include <queue>
#include <string>

#include <SFML/Network.hpp>

#include "Debug.h"
#include "Settings.h"
#include "Crypto.h"

/**
    A network instruction is a simple structure that keeps the style of
    any instructions sent over a socket consistent on both ends, for
    all types of messages.
**/

struct NetworkInstruction {
public:
    unsigned char type;
    std::string subject;
    std::string details;
    NetworkInstruction ( unsigned char t, std::string s, std::string d )
    {
        type = t;
        subject = s;
        details = d;
    }
};

/**
    The Network Manager handles communications between the client and the server, including
    player input, entity positioning and spawning, time synchronisation, and logging in.
**/

class NetworkManager {
public:
    static void InitialiseSockets ();
    static void Update();
    static void EndConnection();
    static void Login ( std::string username, std::string password );

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
