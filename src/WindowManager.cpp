#include "WindowManager.h"

sf::RenderWindow WindowManager::window;

void WindowManager::Clear()
{
    window.clear(sf::Color::White);
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

void WindowManager::CheckEvents()
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            window.close();
        }
    }
}

bool WindowManager::WindowIsOpen()
{
    return window.isOpen();
}

void WindowManager::Draw(sf::Drawable& object)
{
    window.draw(object);
}
