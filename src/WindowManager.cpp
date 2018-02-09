/**     Alex Garrity, 2018      **/

#include "WindowManager.h"

// Redeclare the render window as it's private static within a class
sf::RenderWindow WindowManager::window;

// Clears the window
void WindowManager::Clear()
{
    //Clear the window with the colour white
    window.clear (sf::Color::White);
}

// Displays drawn objects to the window
void WindowManager::Display()
{
    //Display all drawn objects to the window
    window.display();
}

// Either locks the framerate to whatever's specified, or enables vsync
// No unlimited framerates are accepted here.
// framerate is unsigned as you can't have a negative framerate
void WindowManager::SetFramerate (unsigned int framerate)
{
    //If the framerate given is not 0
    if (framerate != 0)
    {
        //Set the max framerate to the given framerate
        window.setFramerateLimit (framerate);
    }
    else
    {
        //If the given framerate is 0, enable VSync
        window.setVerticalSyncEnabled (true);
    }
}

// Creates an instance of the render window using the specified sizes, depth, and string
void WindowManager::CreateWindow (short x, short y, short depth, const char name[])
{
    window.create (sf::VideoMode (x, y, depth), name);
}

// Basically just checks that the window is still open for now
// If the close button is pressed, it closes the window
void WindowManager::CheckEvents()
{
    sf::Event event;                                //Create a new SFML event

    while (window.pollEvent (event) )               //While the window is polling for the event...
    {
        UIManager::CheckInput (event);              //Make the UI manager check for inputs, using the event

        if (event.type == sf::Event::Closed)        //If the event type is 'closed'
        {
            window.close();                         //Close the window
        }
    }
}

// Returns whether or not the window is open
bool WindowManager::WindowIsOpen()
{
    //Return the result of the isOpen function
    return window.isOpen();
}

// Draws a passed drawable to the window
void WindowManager::Draw (sf::Drawable& object)
{
    //Draw the given object to the window
    window.draw (object);
}

sf::RenderWindow &GetWindow()
{
    return &window;
}
