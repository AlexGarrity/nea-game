/**     Alex Garrity, 2018      **/

#include "StateManager.h"

std::stack<GameState*> StateManager::stateList;

void StateManager::PushState(GameState* state)
{
    //Push the given state to the state queue
    stateList.push(state);
}

void StateManager::Update()
{
    //If the state queue isn't empty...
    if (!stateList.empty()) {
        //Create a pointer to a GameState, and remove the state on top
        GameState* state = PopState();
        //Call the state's input function
        state->Input();
        //Call the state's update function
        state->Update();
        //Call the state's draw function
        state->Draw();
    }
}

GameState* StateManager::PopState()
{
    //Create a new GameState pointer, and set it to the value of the pointer at the front of the queue
    GameState* state = stateList.top();
    //Delete the pointer at the top of the queue
    stateList.pop();
    //Return the state
    return state;
}
