#include "Engine.h"

Engine::Engine()
{
    WindowManager::SetFramerate(60);
    NetworkManager::InitialiseSockets("127.0.0.1", 6401, 6402);
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
    while (WindowManager::WindowIsOpen())
    {
        WindowManager::Clear();
        WindowManager::CheckEvents();
        stateManager.Update();
        WindowManager::Display();
    }
}
