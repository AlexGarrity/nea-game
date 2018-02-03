/**     Alex Garrity, 2018      **/

#include "NetworkManager.h"

sf::TcpSocket NetworkManager::tcpSocket;            //Forward declare both sockets used
sf::UdpSocket NetworkManager::udpSocket;

std::queue <NetworkInstruction> NetworkManager::updateQueueUp;         //Forward declare instruction queues
std::queue <NetworkInstruction> NetworkManager::updateQueueDown;

sf::IpAddress Settings::serverAddress;          //Forward declare settings
unsigned short Settings::gameUDPPort;
unsigned short Settings::loginTCPPort;

sf::Packet NetworkManager::tcpDownPacket;       //Forward declare packets
sf::Packet NetworkManager::tcpUpPacket;         //      TCP is used by the login server
sf::Packet NetworkManager::udpDownPacket;       //      UDP is used by the game
sf::Packet NetworkManager::udpUpPacket;         //Format for sending messages should be type (char), subject (string), details (string).
/*Type is the type of message.  For example; Conn, Move...
  Subject is what's being affected, represented by a UUID or some other detail
  Detail is what's actually changing or being set
*/

const char Settings::UUID[] = "00000000";       //Default to a null UUID.  If this reaches the server, something has gone wrong
bool Settings::LoggedIn = false;


void NetworkManager::InitialiseSockets(sf::IpAddress ipAddress, unsigned short tcpPort, unsigned short udpPort)
{
    if (tcpSocket.connect(ipAddress, tcpPort) != sf::TcpSocket::Done) {
        Debug::Log("TCP socket connected successfully", Debug::Trace);
    }
    else {
        Debug::Log("TCP socket failed to connect.  Is the server online?", Debug::Warn);
    }
    if (udpSocket.bind(udpPort) != sf::UdpSocket::Done) {
        Debug::Log("UDP socket bound successfully", Debug::Trace);
    }
    else {
        Debug::Log("UDP socket failed to bind to port", Debug::Warn);
    }
}


void NetworkManager::EndConnection()
{

    unsigned char type = 2;                          //The message type is a disconnect (Type 2)
    std::string subject = Settings::UUID;   //The subject of the disconnect is the user
    std::string details = "";               //Added for consistency
    bool canDisconnectSafely = false;       //Check used later in a loop

    Debug::Log("Ending connection", Debug::Info);                           //Log that the process has started
    tcpSocket.connect(Settings::serverAddress, Settings::loginTCPPort);     //Connect to the login server instead of the game server

    tcpUpPacket << type << subject << details;          //Load the message type and subject into the packet
    tcpSocket.send(tcpUpPacket);                        //Send the packet to the server
    Debug::Log("Sent disconnect signal", Debug::Info);  //Log that this has happened

    while (!canDisconnectSafely) {                            //While the client can't disconnect safely...
        if (tcpSocket.receive(tcpDownPacket)) {                 //Receive a packet through the TCP socket, and load it into the TCP downwards packet
            tcpDownPacket >> type >> subject >> details;        //Take the packet contents and put them into type and subject
            if (type == 3) {                                    //If the type of message received is a confirmation...
                if (subject == Settings::UUID)                  //If the server is confirming a disconnection...
                    if (details == "True") {                    //Checks for package
                        canDisconnectSafely = true;             //Set canDisconnectSafely to true
                    }
            }
        }

    }
    Debug::Log ("The client has safely disconnected", Debug::Info);     //Log that the client has disconnected safely
}

void NetworkManager::Login(std::string username, std::string password)
{
    unsigned char type = '1';
    std::string subject = sha256(username);
    std::string details = sha256(password);

    tcpUpPacket << type << subject << details;
    tcpSocket.send(tcpUpPacket);
    if (tcpSocket.receive(tcpDownPacket)) {
        if (tcpDownPacket >> type >> subject >> details) {
            if (type == '3' && subject == "Auth") {
                if (details == "True") {
                    Settings::LoggedIn = true;
                    Settings::userHash = subject;
                    Settings::passHash = details;
                }
            }
        }
    }
}


void NetworkManager::ChangeServer()
{
    //Should just switch the port to the login server port rather than the game port, and vice versa.
    tcpSocket.connect(Settings::serverAddress, Settings::loginTCPPort);
}


void NetworkManager::Update()
{
    //ClearQueues();            //Used for clearing instruction queues.  May enable this under a condition at some later date if too many end up unprocessed
    GetUpdates();               //Pull updates from the server
    ProcessUpdates();           //Process the updates (maybe on a separate thread)
    PushUpdates();              //Push and client changes to the server
}


void NetworkManager::GetUpdates()
{
    udpSocket.receive(udpDownPacket, Settings::serverAddress, Settings::gameUDPPort);
}


void NetworkManager::PushUpdates()
{
    while (updateQueueDown.size() > 0) {
        NetworkInstruction currentInstruction = updateQueueDown.front();
        udpUpPacket << currentInstruction.type << currentInstruction.subject << currentInstruction.details;
        udpSocket.send(udpUpPacket, Settings::serverAddress, Settings::gameUDPPort);
    }
}


void NetworkManager::ProcessUpdates()
{
    unsigned char type;
    std::string subject, details;
    if (udpDownPacket >> type >> subject >> details) {                  //If the read is successful...
        Debug::Log("UDP down packet has contents", Debug::Info);        //Log that the packet isn't empty
        NetworkInstruction networkInstruction(type, subject, details);
        updateQueueDown.push(networkInstruction);                       //Add a new instruction to the update queue
    }
}


void NetworkManager::ClearQueues()          //Not currently used, might add in the event that the queue gets too long
{
    while (updateQueueDown.size() > 0) {
        updateQueueDown.pop();
    }
    while (updateQueueUp.size() > 0) {
        updateQueueUp.pop();
    }
}
