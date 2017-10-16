#include "NetworkManager.h"

NetworkManager::NetworkManager()
{
    //ctor
}

NetworkManager::~NetworkManager()
{
    //dtor
}

void NetworkManager::InitialiseSockets()
{
    sf::Socket::Status status = tcp.connect("127.0.0.1", 6401);
    if (status != sf::Socket::Done)
    {
        Debug::Log("Could not connect to server", Debug::Critical);
    }
    else
    {
        Debug::Log("Connected successfully", Debug::Warning);
    }
}
