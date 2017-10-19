#ifndef WINDOWMANAGER_H
#define WINDOWMANAGER_H

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>

class WindowManager
{
public:
    static void Clear();
    static void Display();
    static void SetFramerate(unsigned int framerate);
    static void CreateWindow(short x, short y, short depth, const char name[]);

    static void CheckEvents();
    static bool WindowIsOpen();

    static void Draw(sf::Drawable& object);


protected:

private:
    static sf::RenderWindow window;
};



#endif // WINDOWMANAGER_H
