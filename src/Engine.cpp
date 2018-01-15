/**     Alex Garrity, 2018      **/

#include "Engine.h"

// Constructor that I deleted was here.


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

void Engine::GraphicsUpdate()
{
    ObjectManager::DrawObjects();
    UIManager::Update();
    WindowManager::Clear();
    WindowManager::Display();
}

void Engine::NetworkUpdate()
{
    NetworkManager::Update();
    ObjectManager::UpdateObjects();
}

/**
    Game Loop -
        Checks if the window is open
        If it is:
            Check that the user hasn't tried to close the window, and that it's still in focus
            Update the frame time
            Update the state manager
            Clear the window
            Display objects drawn to the window
        If not:
            End the loop (closes the application)
**/

void Engine::GameLoop()
{
    while (WindowManager::WindowIsOpen()) {
        Time::Update();
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
        > This might yet turn into the actual gameloop...
    It's also a total mess...
**/

void Engine::TestLoop()
{
    ResourceManager::Load("assets/texture.png", "texture");
    //ObjectManager::CreateObject("texture", 50, 50);

    //std::thread graphicsThread(Engine::GraphicsUpdate);           // Drawing and updating objects may be done on a separate thread
    std::thread networkThread(&Engine::NetworkUpdate, this);      // Sending and receiving data to and from the server is done in a separate thread

    while (WindowManager::WindowIsOpen()) {
        WindowManager::CheckEvents();
        GraphicsUpdate();       //Updating graphics is on the main thread for now
    }
    //graphicsThread.join();
    networkThread.detach();     //Detach here as opposed to join as otherwise the network would have to wait for the next update
    NetworkManager::EndConnection();    //Tell the server that the connection has been closed, and free up the ports
}
