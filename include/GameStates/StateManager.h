#ifndef STATEMANAGER_H
#define STATEMANAGER_H

#include "GameState.h"
#include <stack>

class StateManager
{
    public:
        /** Default constructor */
        StateManager();
        /** Default destructor */
        virtual ~StateManager();

        void Update();
        void PushState(GameState* state);
        GameState* PopState();

    protected:

    private:
        std::stack <GameState*> stateList;
};

#endif // STATEMANAGER_H
