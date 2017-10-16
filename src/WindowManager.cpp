#include "WindowManager.h"

void WindowManager::Clear()
{
    window.clear(sf::Color::Red);
}

void WindowManager::Display()
{
    window.display();
}

void WindowManager::SetFramerate(unsigned int framerate)
{
    window.setFramerateLimit(framerate);
}

void WindowManager::CreateWindow(short x, short y, short depth, const char name[])
{
    window.create(sf::VideoMode(x, y, depth), name);
}
