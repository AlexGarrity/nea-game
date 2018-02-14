/**     Alex Garrity, 2018      **/

#ifndef WINDOWMANAGER_H
#define WINDOWMANAGER_H

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>

/** Entire class is static since basically everything accesses this is some way or another **/

/**
    The Window Manager is dedicated to the window.  It draws objects to it, displays objects
    drawn to it, checks that it's still open, and does its initial setup.
**/

class WindowManager {
public:
    static void Clear();
    static void Display();
    static void SetFramerate ( unsigned int framerate );
    static void CreateWindow ( short x, short y, short depth, const char name[] );

    static void CheckEvents();
    static bool WindowIsOpen();

    static void Draw ( sf::Drawable& object );

    static sf::RenderWindow &GetWindow();


protected:

private:
    static sf::RenderWindow window;
};



#endif // WINDOWMANAGER_H
