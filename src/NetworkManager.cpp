#include "NetworkManager.h"

sf::TcpSocket NetworkManager::tcp;
sf::UdpSocket NetworkManager::udp;

sf::IpAddress NetworkManager::serverAddress;
unsigned short NetworkManager::UDPPort;
unsigned short NetworkManager::TCPPort;

void NetworkManager::InitialiseSockets(const char* address, unsigned short tPort, unsigned short uPort)
{
    serverAddress = address;
    TCPPort = tPort;
    UDPPort = uPort;
    BindTCP();
    BindUDP();
}

void NetworkManager::BindTCP ()
{
    sf::Socket::Status status = tcp.connect(serverAddress, TCPPort);
    if (status != sf::Socket::Done) {
        Debug::Log("Could not connect TCP socket", Debug::Error);
    } else {
        Debug::Log("Connected successfully", Debug::Info);
    }
}

void NetworkManager::BindUDP()
{
    sf::Socket::Status status = udp.bind(UDPPort);
    if (status != sf::Socket::Done) {
        Debug::Log("Could not bind UDP socket \nThis means that something has gone badly wrong.", Debug::Error);
    } else {
        Debug::Log("Bound UDP port successfully", Debug::Info);
    }
}

void NetworkManager::SendTCP(char message[64])
{
    sf::Packet packet;
    packet.append(message, 64);
    tcp.send(packet);
}

void NetworkManager::SendUDP(char message[64])
{
    sf::Packet packet;
    packet.append(message, 64);
    udp.send(packet, serverAddress, UDPPort);
}

void NetworkManager::ReceiveTCP()
{
    sf::Packet packet;
    tcp.receive(packet);
}

void NetworkManager::ReceiveUDP()
{
    sf::Packet packet;
    udp.receive(packet, serverAddress, UDPPort);
}
