#ifndef STATEMANAGER_H
#define STATEMANAGER_H

#include <queue>
#include "Timing.h"

class Gamestate;

class StateManager {
public:
    static void Start();
    static void Update();

    static void PushState (Gamestate *gamestate);
    static void PopState();

    static Gamestate* GetState();

protected:

private:
    static Gamestate* currentGamestate;

    static std::queue<Gamestate*> stateQueue;
    static bool exiting;
    static float timeToNextUpdate;
    static float lastFrameTime;
};

#endif // STATEMANAGER_H
