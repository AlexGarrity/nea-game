#include "StateManager.h"

std::queue<Gamestate*> StateManager::stateQueue;

bool NetworkManager::loggedIn = false;

void StateManager::Start()
{
    if (stateQueue.empty() ) {
        PushState (new GamestateLogin() );
    }
}

void StateManager::Update()
{
    Gamestate *gamestate = GetState();
    gamestate->Input();
    gamestate->Update();
    gamestate->Draw ();
}

void StateManager::PopState()
{
    stateQueue.pop();
}

Gamestate* StateManager::GetState()
{
    return stateQueue.front();
}

Gamestate* StateManager::NextState()
{
    if (!NetworkManager::GetLoggedIn() ) {
        return new GamestateLogin();
    }
    else if (false) {

    }
    else {
        return new GamestateGameplay();
    }
}

void StateManager::PushState (Gamestate *gamestate)
{
    if (gamestate != nullptr) {
        stateQueue.push (gamestate);
    }
}
