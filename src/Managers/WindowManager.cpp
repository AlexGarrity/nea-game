#include "WindowManager.h"

sf::RenderWindow WindowManager::window;

void WindowManager::CreateWindow (unsigned short wX, unsigned short wY, unsigned char bD, std::string wN)
{
    window.create (sf::VideoMode (wX, wY, bD), wN, sf::Style::None);
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
    }
}

void WindowManager::Update()
{
    sf::Event e;

    while (window.pollEvent (e) ) {
        PollEvent (e);
    }

    window.clear (sf::Color::White);
    window.display();
}

void WindowManager::Draw (sf::Drawable &d, const sf::RenderStates &rS)
{
    window.draw (d, rS);
}
