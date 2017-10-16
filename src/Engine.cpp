#include "Engine.h"

Engine::Engine()
{
    WindowManager::SetFramerate(60);
    networkManager.InitialiseSockets();
}

void Engine::Start(short x, short y, short depth, const char name[])
{
    WindowManager::CreateWindow(x, y, depth, name);
    GameLoop();
}

void Engine::UpdateWindow()
{
    WindowManager::Display();
}


void Engine::GameLoop()
{
    WindowManager::Clear();
    stateManager.Update();
    WindowManager::Display();
}
