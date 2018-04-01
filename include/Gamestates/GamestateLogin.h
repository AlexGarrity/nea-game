#ifndef GAMESTATELOGIN_H
#define GAMESTATELOGIN_H

#include "Gamestate.h"


class GamestateLogin : public Gamestate {
public:
    GamestateLogin();
    virtual ~GamestateLogin();

    void Input();
    void Update();
    void Draw ();

protected:

private:
    bool loggedIn;
};

#endif // GAMESTATELOGIN_H
