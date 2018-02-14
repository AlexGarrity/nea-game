/**     Alex Garrity, 2018      **/

#ifndef GS_LOGIN_H
#define GS_LOGIN_H

#include "GameState.h"

/**
    Login is the state of the game whilst the user is trying to log into the game server.
    In this state, no network requests happen, expect when sending credentials and
    awaiting authentication.  Only the login screen will be drawn.
**/

class GS_Login : public GameState {
public:
    void Input();
    void Update();
    void Draw();
protected:
private:
};

#endif // GS_LOGIN_H
