#include "Managers/WindowManager.h"

sf::RenderWindow WindowManager::window;
char WindowManager::input;

void WindowManager::CreateWindow (unsigned short wX, unsigned short wY, unsigned char bD, std::string wN)
{
    window.create (sf::VideoMode (wX, wY, bD), wN);
    window.setPosition (sf::Vector2i (0,0) );
    window.setVerticalSyncEnabled (true);
}

bool WindowManager::WindowOpen()
{
    return window.isOpen();
}

sf::RenderWindow &WindowManager::GetWindow()
{
    return window;
}

void WindowManager::ClearScreen()
{
    window.clear(sf::Color::Black);
}

void WindowManager::PollEvent (sf::Event &e)
{
    switch (e.type) {
    case sf::Event::Closed:
        window.close();
        NetworkManager::Disconnect();
        break;

    case sf::Event::LostFocus:
        //Push paused state
        break;

    case sf::Event::Resized:
        //Do something.  It sounds kind of useful.
        break;
    case sf::Event::TextEntered:
        if (e.text.unicode < 128) {
            input = static_cast<char>(e.text.unicode);
            std::cout << "Keyboard input: " << input << std::endl;
        }
        break;
    }
}

void WindowManager::Update()
{
    input = 0;

    sf::Event e;
    while (window.pollEvent (e) ) {
        PollEvent (e);
    }

    window.display();
}

char WindowManager::GetInput()
{
    return input;
}

void WindowManager::Draw (sf::Drawable *d, const sf::RenderStates &rS)
{
    window.draw(*d, rS);
}
