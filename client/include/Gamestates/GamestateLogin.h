#ifndef GAMESTATELOGIN_H
#define GAMESTATELOGIN_H

#include <functional>

#include "Gamestate.h"
#include "GamestateGameplay.h"

class GamestateLogin : public Gamestate {
public:
    GamestateLogin();
    virtual ~GamestateLogin();

    void Input();
    void Update();
    void Draw ();

protected:

private:
    void AttemptLogin();

    UITextField *nameField = nullptr;
    UITextField *passField = nullptr;
    UIButton *loginButton = nullptr;

    bool loggedIn = false;
};

#endif // GAMESTATELOGIN_H
