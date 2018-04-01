#include "NetworkManager.h"

sf::TcpSocket NetworkManager::tcpSocket;
sf::UdpSocket NetworkManager::udpSocket;

sf::IpAddress NetworkManager::ipAddress = "127.0.0.1";
unsigned short NetworkManager::tcpPort = 6401;
unsigned short NetworkManager::udpPort = 6402;

std::string NetworkManager::userHash = "";
bool NetworkManager::loggedIn = false;

sf::Packet NetworkManager::packet;

std::queue<NetworkInstruction*> NetworkManager::downQueue;
std::queue<NetworkInstruction*> NetworkManager::upQueue;


bool NetworkManager::Connect()
{
    tcpSocket.disconnect();

    if (tcpSocket.connect (ipAddress, tcpPort) != sf::Socket::Done) {
        return false;
    }

    if (udpSocket.bind (udpPort) != sf::Socket::Done) {
        return false;
    }

    return true;
}

void NetworkManager::Disconnect()
{
    unsigned char type = 01;
    std::string subject, details;

    if (ipAddress.toString() == "127.0.0.1") {
        subject = "127.0.0.1";
    }
    else {
        subject = sf::IpAddress::getPublicAddress().toString();
        details = userHash;
    }

    details = "false";
    packet.clear();
    packet << type << subject << details;
    tcpSocket.send (packet);
    tcpSocket.disconnect();
}

bool NetworkManager::AttemptLogin (std::string username, std::string password)
{
    //Hash the two strings here...
    std::string uHash = sha256 (username);
    std::string pHash = sha256 (password);

    packet << 01 << uHash << pHash;

    if (tcpSocket.send (packet) == sf::Socket::Done) {
        packet.clear();

        if (tcpSocket.receive (packet) == sf::Socket::Done) {
            NetworkInstruction response (0, "", "");
            packet >> response.type >> response.subject >> response.details;

            if (response.type == 02 && response.subject == username && response.details == "true") {
                userHash = uHash;
                loggedIn = true;
                return true;
            }
        }
    }

    return false;
}

bool NetworkManager::GetLoggedIn()
{
    return loggedIn;
}

void NetworkManager::PullInstructions()
{
    if (udpSocket.receive (packet, ipAddress, udpPort) == sf::Socket::Done) {
        ParsePacket();
    }
}

void NetworkManager::ParsePacket()
{
    unsigned char type;
    std::string subject;
    std::string details;
    packet >> type >> subject >> details;

    NetworkInstruction *nI = new NetworkInstruction (type, subject, details);
    downQueue.push (nI);
    packet.clear();
}

void NetworkManager::PushInstructions()
{
    NetworkInstruction *instruction = nullptr;

    while (!upQueue.empty() ) {
        instruction = upQueue.front();
        upQueue.pop();

        packet << instruction->type << instruction->subject << instruction->details;
        udpSocket.send (packet, ipAddress, udpPort);
        packet.clear();
    }

    delete instruction;
}

void NetworkManager::Update()
{
    PushInstructions();
    PullInstructions();
}

void NetworkManager::AddInstruction (NetworkInstruction networkInstruction)
{
    upQueue.push (&networkInstruction);
}
