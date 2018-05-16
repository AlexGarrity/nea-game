#ifndef WINDOWMANAGER_H
#define WINDOWMANAGER_H

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Event.hpp>

#include "NetworkManager.h"

class WindowManager {
public:
    static void CreateWindow (unsigned short windowX, unsigned short windowY, unsigned char bitDepth, std::string windowName);
    static void Update();
    static void Draw (sf::Drawable *d, const sf::RenderStates &rS = sf::RenderStates::Default);
    static void ClearScreen();

    static char GetInput();
    static bool WindowOpen();
    static sf::RenderWindow &GetWindow();

protected:

private:
    static void PollEvent (sf::Event &e);

    static sf::RenderWindow window;
    static char input;
};

#endif // WINDOWMANAGER_H
