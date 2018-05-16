#include "GamestateLogin.h"

GamestateLogin::GamestateLogin()
{
    UIManager::ClearElements();

    nameField = new UITextField(sf::Vector2f(200, 100), sf::Vector2u(880, 100), ResourceManager::GetTexture("UI_Text_Field"), "Username", ResourceManager::GetFont(), nullptr);
    passField = new UITextField(sf::Vector2f(200, 250), sf::Vector2u(880, 100), ResourceManager::GetTexture("UI_Text_Field"), "Password", ResourceManager::GetFont(), nullptr);
    loginButton = new UIButton(sf::Vector2f(340, 400), sf::Vector2u(600, 200), ResourceManager::GetTexture("UI_Button_Login"), std::bind(&GamestateLogin::AttemptLogin, this), nullptr);

    UIManager::AddElement("2Username", nameField);
    UIManager::AddElement("1UsernameBox", new UIImage(sf::Vector2f(200, 100), sf::Vector2u(880,100), ResourceManager::GetTexture("UI_Text_Field"), nameField));
    UIManager::AddElement("2Password", passField);
    UIManager::AddElement("1PasswordBox", new UIImage(sf::Vector2f(200,250), sf::Vector2u(880,100), ResourceManager::GetTexture("UI_Text_Field"), passField));
    UIManager::AddElement("2Login", loginButton);

    std::cout << "Current gamestate is login" << std::endl;
}

GamestateLogin::~GamestateLogin()
{
    //dtor
}

void GamestateLogin::Input()
{
    UIManager::Update();
}

void GamestateLogin::Update()
{
    if (NetworkManager::GetLoggedIn()) {
        StateManager::PopState();
        StateManager::PushState(new GamestateGameplay());
        std::cout << "Pushed a new Gameplay Gamestate" << std::endl;
    }
    NetworkManager::Update();
}

void GamestateLogin::Draw ()
{
    WindowManager::ClearScreen();
    UIManager::Draw();
    WindowManager::Update();
}


void GamestateLogin::AttemptLogin()
{
    std::cout << "Attempting login with parameters " << nameField->GetText() << " and " << passField->GetText() << "\n";
    std::string passHash = sha256(passField->GetText());
    NetworkManager::AttemptLogin(nameField->GetText(), passHash);
    loggedIn = NetworkManager::GetLoggedIn();
    std::cout << "loggedIn: " << loggedIn <<  std::endl;
    return;
}
