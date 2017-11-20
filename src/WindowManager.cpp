#include "WindowManager.h"

// Redeclare the render window as it's private static within a class
sf::RenderWindow WindowManager::window;

// Clears the window
void WindowManager::Clear()
{
    window.clear(sf::Color::White);
}

// Displays drawn objects to the window
void WindowManager::Display()
{
    window.display();
}

// Either locks the framerate to whatever's specified, or enables vsync
// No unlimited framerates are accepted here.
// framerate is unsigned as you can't have a negative framerate
void WindowManager::SetFramerate(unsigned int framerate)
{
    if (framerate != 0) {
        window.setFramerateLimit(framerate);
    } else {
        window.setVerticalSyncEnabled(true);
    }
}

// Creates an instance of the render window using the specified sizes, depth, and string
void WindowManager::CreateWindow(short x, short y, short depth, const char name[])
{
    window.create(sf::VideoMode(x, y, depth), name);
}

// Basically just checks that the window is still open for now
// If the close button is pressed, it closes the window
void WindowManager::CheckEvents()
{
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }
    }
}
// Returns whether or not the window is open
bool WindowManager::WindowIsOpen()
{
    return window.isOpen();
}

// Draws a passed drawable to the window
void WindowManager::Draw(sf::Drawable& object)
{
    window.draw(object);
}
