#include "Gamestates/GamestateGameplay.h"

GamestateGameplay::GamestateGameplay()
{
    UIManager::ClearElements();
    UIManager::AddElement("2Health", new UIImage(sf::Vector2f(50,50), sf::Vector2u(100, 50), ResourceManager::GetTexture("UI_Status_Bar"), nullptr));
    UIManager::AddElement("2Magic", new UIImage(sf::Vector2f(50,80), sf::Vector2u(100, 50), ResourceManager::GetTexture("UI_Status_Bar"), nullptr));
    UIManager::AddElement("2Stamina", new UIImage(sf::Vector2f(50,110), sf::Vector2u(100, 50), ResourceManager::GetTexture("UI_Status_Bar"), nullptr));

    std::cout << "Current gamestate is gameplay" << std::endl;
}

GamestateGameplay::~GamestateGameplay()
{
    //dtor
}

void GamestateGameplay::Input()
{
    UIManager::Update();
}

void GamestateGameplay::Update()
{
    NetworkManager::Update();
}

void GamestateGameplay::Draw ()
{
    WindowManager::ClearScreen();
    UIManager::Draw();
    WindowManager::Update();
}
