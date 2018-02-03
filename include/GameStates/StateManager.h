/**     Alex Garrity, 2018      **/

#ifndef STATEMANAGER_H
#define STATEMANAGER_H

#include <stack>

#include "GameState.h"
#include "GS_Gameplay.h"
#include "GS_Login.h"
#include "GS_Initialise.h"

class StateManager {
public:
    static void Initialise();
    static void Update();
    static void PushState(GameState* state);
    static GameState* PopState();

protected:

private:
    static std::stack <GameState*> stateList;
};

#endif // STATEMANAGER_H
