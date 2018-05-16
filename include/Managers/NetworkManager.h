#ifndef NETWORKMANAGER_H
#define NETWORKMANAGER_H

#include <SFML/Network.hpp>

#include <queue>
#include <sstream>

#include "Crypto.h"
#include "EntityManager.h"

struct NetworkInstruction {
public:
    NetworkInstruction() {

    }
    NetworkInstruction (sf::Uint8 t, sf::String s, sf::String d)
    {
        type = t;
        subject = s;
        details = d;
    }

    bool Send(sf::TcpSocket &socket) {
        sf::Packet packet;
        packet << type << subject  << details;
        if (socket.send(packet) == sf::Socket::Done) {
            return true;
        }
        return false;
    }

    bool Receive(sf::TcpSocket &socket) {
        sf::Packet packet;
        sf::Socket::Status status = sf::Socket::Error;
        status = socket.receive(packet);
        if (status == sf::Socket::Done) {
            packet >> type >> subject >> details;
            std::cout << "Received " << type << ", " << subject.toAnsiString() << ", " << details.toAnsiString() << std::endl;
            return true;
        }
        return false;
    }

    void Clear() {
        type = 255;
        subject = "";
        details = "";
    }

    sf::Uint8 type;
    sf::String subject;
    sf::String details;
};

class NetworkManager {
public:
    static void Disconnect();
    static bool Connect();
    static void Update();

    static void AddInstruction (NetworkInstruction *nInstruction);

    static void AttemptLogin (std::string username, std::string password);
    static bool GetLoggedIn();

    static std::queue<NetworkInstruction*> upQueue;
    static std::queue<NetworkInstruction*> downQueue;

    static void Parse();

protected:

private:
    static void PullInstructions();
    static void PushInstructions();

    static void ParsePacket(NetworkInstruction &instruction);

    static sf::SocketSelector socketSelector;
    static sf::TcpSocket tcpSocket;
    static sf::IpAddress ipAddress;
    static unsigned short tcpPort;

    static std::string userHash;
    static bool loggedIn;

    static sf::Packet packet;

};

#endif // NETWORKMANAGER_H
