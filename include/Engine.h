#ifndef ENGINE_H
#define ENGINE_H

#include <string>

#include "WindowManager.h"
#include "NetworkManager.h"
#include "StateManager.h"

class Engine {
public:
    static bool Start (unsigned short screenX, unsigned short screenY, unsigned char bitDepth, std::string windowName);

protected:

private:
    static void GameLoop();
};

#endif // ENGINE_H
