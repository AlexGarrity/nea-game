#include "GamestateInitialise.h"

GamestateInitialise::GamestateInitialise()
{
    ResourceManager::Initialise();
    WindowManager::CreateWindow (1280, 720, 32, "Never doing this again...  Or maybe I will.");

    UIManager::AddElement ("Splash", new UIImage (sf::Vector2f (0,0), WindowManager::GetWindow().getSize(), ResourceManager::GetTexture ("UI_Splash") ) );

    bool successfulConnection = NetworkManager::Connect();

    if (successfulConnection) {
        std::cout << "Connected to server \n";
        StateManager::PushState (new GamestateLogin());
        std::cout << "Pushed a new login gamestate \n";
        //StateManager::PopState();
        std::cout << "Popped the state \n";
    }
    else {
        UIManager::RemoveElement("Splash");
        UIManager::AddElement ("NoConnect", new UIImage (sf::Vector2f (100, 100), WindowManager::GetWindow().getSize() - sf::Vector2u (200, 200), ResourceManager::GetTexture ("error_no_connection")));
    }

    std::cout << "Current gamestate is initialise" << std::endl;
}

GamestateInitialise::~GamestateInitialise()
{
    UIManager::ClearElements();
}

void GamestateInitialise::Input()
{

}

void GamestateInitialise::Update()
{


}

void GamestateInitialise::Draw()
{
    WindowManager::ClearScreen();
    UIManager::Draw();
    WindowManager::Update();
}

