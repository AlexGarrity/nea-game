#include "Engine.h"

// Constructor that I'm not using for some reason...

Engine::Engine() {

}

/**
    Start -
        Not particularly sure why I used this as opposed to a constructor
        I might make the engine static later.  Or turn this into a singleton.
**/

bool Engine::Start(short x, short y, short depth, const char name[])
{
    WindowManager::CreateWindow(x, y, depth, name);
    WindowManager::SetFramerate(0);
    NetworkManager::InitialiseSockets("127.0.0.1", 6401, 6402);
    if (WindowManager::WindowIsOpen()) {
        /** TODO:  Change this to GameLoop() once the state manager works **/
        TestLoop();
    } else {
        return false;
    }
    return true;
}

/**
    Game Loop -
        Checks if the window is open
        If it is:
            Check that the user hasn't tried to close the window, and that it's still in focus
            Update the state manager
            Clear the window
            Display objects drawn to the window
        If not:
            End the loop (closes the application)
**/

void Engine::GameLoop()
{
    while (WindowManager::WindowIsOpen()) {
        WindowManager::CheckEvents();
        StateManager::Update();
        WindowManager::Clear();
        WindowManager::Display();
    }
}

/**
    This version of the game loop is purely for test purposes.
    When something new gets implemented, it gets tested here first.
    This is NOT the actual game loop.
    It's also a total mess...
**/
void Engine::TestLoop()
{
    ResourceManager::Load("assets/texture.png", "texture");
    //ObjectManager::CreateObject();    Currently disabled as only have GameObject type for now.
    while (WindowManager::WindowIsOpen()) {
        WindowManager::CheckEvents();
        ObjectManager::UpdateObjects();
        WindowManager::Clear();
        WindowManager::Display();
    }
}
