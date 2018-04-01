#include "GamestateLogin.h"

GamestateLogin::GamestateLogin()
{

}

GamestateLogin::~GamestateLogin()
{
    //dtor
}

void GamestateLogin::Input()
{

}

void GamestateLogin::Update()
{
    UIManager::Update();
}

void GamestateLogin::Draw ()
{
    UIManager::Draw();
    WindowManager::Update();
}
