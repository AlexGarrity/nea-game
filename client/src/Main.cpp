/**     Alex Garrity, 2018      **/

#include "Managers/StateManager.h"
#include "Gamestates/GamestateInitialise.h"

/**
    Main Function -
        Creates and instance of the engine, then checks if it's started correctly
        If it starts correctly, then the process will run and return 0 at the end
        If it doesn't, the process returns 17 (this is a dumb arbitrary value that means nothing)
**/

int main()
{
    StateManager::Start();
    StateManager::PushState (new GamestateInitialise() );
    StateManager::Update();
}
