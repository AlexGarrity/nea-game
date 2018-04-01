#ifndef STATEMANAGER_H
#define STATEMANAGER_H

#include <queue>

#include "NetworkManager.h"
#include "WindowManager.h"

#include "Gamestate.h"
#include "GamestateLogin.h"
#include "GamestateGameplay.h"
#include "GamestateMenu.h"

class StateManager {
public:
    static void Start();
    static void Update();

    static void PushState (Gamestate *gamestate);
    static void PopState();

    static Gamestate* GetState();
    static Gamestate* NextState();

protected:

private:
    static std::queue<Gamestate*> stateQueue;
};

#endif // STATEMANAGER_H
