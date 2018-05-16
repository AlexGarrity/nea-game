#include "StateManager.h"

#include "Gamestate.h"

std::queue<Gamestate*> StateManager::stateQueue;
bool StateManager::exiting = false;
Gamestate *StateManager::currentGamestate = nullptr;
float StateManager::timeToNextUpdate = 16.66666666667;
float StateManager::lastFrameTime = 0;

void StateManager::Start()
{

}

void StateManager::Update()
{


    while (!exiting) {
        timeToNextUpdate -= Timing::deltaTime;
        if (timeToNextUpdate >= 0) {
            currentGamestate = GetState();
            currentGamestate->Input();
            currentGamestate->Update();
            currentGamestate->Draw ();

            WindowManager::WindowOpen() ?: exiting = true; //Ternary statement evaluates whether or not the window is still open.  Updates exiting accordingly
            timeToNextUpdate = 16.66666666667 - Timing::deltaTime;      //Set the time to next update to 1/60th of a second, minus the last frame time
        }
    }
}

void StateManager::PopState()
{
    stateQueue.pop();
}

Gamestate* StateManager::GetState()
{
    if (!stateQueue.empty()) {
        return stateQueue.front();
    }
    return nullptr;
}

void StateManager::PushState (Gamestate *gamestate)
{
    if (gamestate != nullptr) {
        stateQueue.push (gamestate);
        std::cout << "Pushed a new state \n";
    }
}
