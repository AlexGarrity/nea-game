#ifndef GAMESTATEINITIALISE_H
#define GAMESTATEINITIALISE_H

#include "Gamestate.h"
#include "GamestateLogin.h"

class GamestateInitialise : public Gamestate {
public:
    GamestateInitialise();
    virtual ~GamestateInitialise();

    void Input();
    void Update();
    void Draw();
protected:

private:
};

#endif // GAMESTATEINITIALISE_H
