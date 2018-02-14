/**     Alex Garrity, 2018      **/

#ifndef STATEMANAGER_H
#define STATEMANAGER_H

#include <stack>

#include "GameState.h"
#include "GS_Gameplay.h"
#include "GS_Login.h"
#include "GS_Initialise.h"

/**
    The state manager handles the change and processing of states.  In ways, it's the
    'real' engine as it handles the way the game flows.  The engine class is more of a
    way to make them all interact properly.
**/

class StateManager {
public:
    static void Initialise();
    static void Update();
    static void PushState ( GameState* state );
    static GameState* PopState();

protected:

private:
    static std::stack <GameState*> stateList;
};

#endif // STATEMANAGER_H
