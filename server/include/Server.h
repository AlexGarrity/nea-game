#ifndef SERVER_H
#define SERVER_H

#include <thread>

#include "Utilities/Timing.h"
#include "Utilities/Logging.h"

#include "Networking/NetworkManager.h"
#include "Objects/ObjectManager.h"
#include "Players/PlayerManager.h"
#include "Map/MapManager.h"
#include "Utilities/Database.h"

class Server
{
public:
    static bool Start();

protected:

private:
    static void Update();

    static void NetworkUpdate();
    static void ObjectUpdate();

    static void FastUpdate();
    static void MediumUpdate();
    static void LongUpdate();

    static float elapsedTime;
    static unsigned char tick;
    static unsigned char lastTick;
};

#endif // SERVER_H
