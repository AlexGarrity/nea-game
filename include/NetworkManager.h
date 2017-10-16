#ifndef NETWORKMANAGER_H
#define NETWORKMANAGER_H

#include <SFML/Network.hpp>
#include "Debug.h"

class NetworkManager
{
    public:
        /** Default constructor */
        NetworkManager();
        /** Default destructor */
        virtual ~NetworkManager();

        void SendUDP();
        void SendTCP();
        void ReceiveUDP();
        void ReceiveTCP();

        void InitialiseSockets();

    protected:

    private:
        sf::TcpSocket tcp;
        sf::UdpSocket udp;
};

#endif // NETWORKMANAGER_H
