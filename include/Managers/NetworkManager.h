#ifndef NETWORKMANAGER_H
#define NETWORKMANAGER_H

#include <SFML/Network.hpp>

#include <queue>

#include "Crypto.h"

struct NetworkInstruction {
public:
    NetworkInstruction (unsigned char t, std::string s, std::string d)
    {
        type = t;
        subject = s;
        details = d;
    }

    unsigned char type;
    std::string subject;
    std::string details;
};

class NetworkManager {
public:
    static void Disconnect();
    static bool Connect();
    static void Update();

    static void AddInstruction (NetworkInstruction nInstruction);

    static bool AttemptLogin (std::string username, std::string password);
    static bool GetLoggedIn();

    static std::queue<NetworkInstruction*> upQueue;
    static std::queue<NetworkInstruction*> downQueue;

    void Parse();

protected:

private:
    static void PullInstructions();
    static void PushInstructions();

    static void ParsePacket();

    static sf::TcpSocket tcpSocket;
    static sf::UdpSocket udpSocket;

    static sf::IpAddress ipAddress;
    static unsigned short udpPort;
    static unsigned short tcpPort;

    static std::string userHash;
    static bool loggedIn;

    static sf::Packet packet;

};

#endif // NETWORKMANAGER_H
