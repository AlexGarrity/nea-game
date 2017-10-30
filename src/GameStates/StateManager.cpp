#include "StateManager.h"

std::stack<GameState*> StateManager::stateList;

void StateManager::PushState(GameState* state)
{
    stateList.push(state);
}

void StateManager::Update()
{
    if (!stateList.empty()) {
        GameState* state = PopState();
        state->Input();
        state->Update();
        state->Draw();
    }
}

GameState* StateManager::PopState()
{
    GameState* state = stateList.top();
    stateList.pop();
    return state;
}
