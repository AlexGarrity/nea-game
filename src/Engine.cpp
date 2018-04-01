#include "Engine.h"

bool Engine::Start (unsigned short screenX, unsigned short screenY, unsigned char bitDepth, std::string windowName)
{
    if (NetworkManager::Connect() ) {
        WindowManager::CreateWindow (screenX, screenY, bitDepth, windowName);
        StateManager::Start();
    }
    else {
        return false;
    }

    GameLoop();
    return true;
}

void Engine::GameLoop()
{
    while (WindowManager::WindowOpen() ) {
        StateManager::Update();
    }
}
