#include "Managers/NetworkManager.h"

sf::TcpSocket NetworkManager::tcpSocket;
sf::SocketSelector NetworkManager::socketSelector;
sf::IpAddress NetworkManager::ipAddress = "127.0.0.1";
unsigned short NetworkManager::tcpPort = 6401;

std::string NetworkManager::userHash = "";
bool NetworkManager::loggedIn = false;

std::queue<NetworkInstruction*> NetworkManager::downQueue;
std::queue<NetworkInstruction*> NetworkManager::upQueue;


bool NetworkManager::Connect()
{
    Disconnect();

    if (tcpSocket.connect (ipAddress, tcpPort) != sf::Socket::Done) {
        return false;
    }

    tcpSocket.setBlocking(false);

    return true;
}

void NetworkManager::Disconnect()       //Something of a courtesy call to the server so that it can log the player out
{
    if (tcpSocket.getRemoteAddress() != sf::IpAddress::None) {
        NetworkInstruction disconnectInstruction(0, userHash, "false");
        disconnectInstruction.Send(tcpSocket);
        disconnectInstruction.Receive(tcpSocket);
        if (disconnectInstruction.details == "true") {
            tcpSocket.disconnect();
        }
    }
}

void NetworkManager::AttemptLogin (std::string username, std::string password)
{
    tcpSocket.setBlocking(true);
    std::cout << "Attempting to log in with: " << username << ", " << password << std::endl;
    NetworkInstruction loginInstruction(01, username, password);
    loginInstruction.Send(tcpSocket);
    loginInstruction.Receive(tcpSocket);
    if (loginInstruction.subject == username) {
        if (loginInstruction.details == "true") {
            loggedIn = true;
        }
    }
}

bool NetworkManager::GetLoggedIn()
{
    return loggedIn;
}

void NetworkManager::PullInstructions()
{
    NetworkInstruction *instruction = new NetworkInstruction;
    if (instruction->Receive(tcpSocket)) {
        downQueue.push(instruction);
    } else {
        delete instruction;
    }
}

void NetworkManager::Parse()
{
    NetworkInstruction *instruction = nullptr;
    while (!downQueue.empty()) {
        instruction = downQueue.front();
        downQueue.pop();
        ParsePacket(*instruction);
        delete instruction;
    }
}

template <typename T>
T StringTo(std::string input) {
    std::stringstream ss;
    ss << input;
    T output;
    ss >> output;
    return output;
}

void NetworkManager::ParsePacket(NetworkInstruction &instruction)
{
    std::cout << "Parsing an instruction: " << instruction.type << ", " << instruction.subject.toAnsiString() << ", " << instruction.details.toAnsiString() << std::endl;
    switch(instruction.type) {
        case sf::Uint8(00):
        {
            //Disconnect
            if (instruction.details == "true") {
                std::cout << "TCP socket has disconnected" << std::endl;
                tcpSocket.disconnect();
            }
            break;
        }
        case sf::Uint8(01):
        {
            //Do nothing, this should only be sent by the client
            break;
        }
        case sf::Uint8(02):
        {
            //Login successful
            if (instruction.subject == userHash) {
                if (instruction.details == "true") {
                    loggedIn = true;
                }
            }
            break;
        }
        case sf::Uint8(12):
        {
            std::string username = instruction.subject.toAnsiString();
            std::string dt = instruction.details.toAnsiString();

            sf::Vector2u worldPos(StringTo<unsigned int>(dt.substr(0, 1)), StringTo<unsigned int>(dt.substr(1, 1)));
            sf::Vector2u cellPos(StringTo<unsigned int>(dt.substr(2, 1)), StringTo<unsigned int>(dt.substr(3, 1)));

            Entity *e = EntityManager::GetEntity(username);
            if (e == nullptr) {
                EntityManager::AddEntity(new Entity(ResourceManager::GetTexture("Entity"), sf::Vector2f(worldPos.x * 250.f, worldPos.y * 250.f) + sf::Vector2f(cellPos.x, cellPos.y)), username);
            } else {
                e->SetPosition(sf::Vector2f(worldPos.x * 250.f, worldPos.y * 250.f) + sf::Vector2f(cellPos.x, cellPos.y));
            }
            break;
        }

    }
}


void NetworkManager::PushInstructions()
{
    NetworkInstruction *instruction = nullptr;

    while (!upQueue.empty()) {
        instruction = upQueue.front();
        upQueue.pop();
        std::cout << "Sent " << std::to_string(instruction->type) << " " << instruction->subject.toAnsiString() << " " << instruction->details.toAnsiString() << std::endl;
        instruction->Send(tcpSocket);
    }

}

void NetworkManager::Update()
{
    PushInstructions();
    PullInstructions();
    Parse();
}

void NetworkManager::AddInstruction (NetworkInstruction *networkInstruction)
{
    upQueue.push (networkInstruction);
}
