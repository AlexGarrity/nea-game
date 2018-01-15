/**     Alex Garrity, 2017      **/

#ifndef STATEMANAGER_H
#define STATEMANAGER_H

#include "GameState.h"
#include "ObjectManager.h"
#include "UIManager.h"
#include <stack>

class StateManager {
public:
    static void Update();
    static void PushState(GameState* state);
    static GameState* PopState();

protected:

private:
    static std::stack <GameState*> stateList;
};

#endif // STATEMANAGER_H
