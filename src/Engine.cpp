#include "Engine.h"

Engine::Engine()
{
    WindowManager::SetFramerate(0);
    NetworkManager::InitialiseSockets("127.0.0.1", 6401, 6402);
}

void Engine::Start(short x, short y, short depth, const char name[])
{
    WindowManager::CreateWindow(x, y, depth, name);
    GameLoop();
}

void Engine::GameLoop()
{
    while (WindowManager::WindowIsOpen()) {
        WindowManager::Clear();
        WindowManager::CheckEvents();
        StateManager::Update();
        WindowManager::Display();
    }
}
