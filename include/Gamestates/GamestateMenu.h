#ifndef GAMESTATEMENU_H
#define GAMESTATEMENU_H

#include "Gamestate.h"


class GamestateMenu : public Gamestate {
public:
    GamestateMenu();
    virtual ~GamestateMenu();

    void Input();
    void Update();
    void Draw ();
protected:

private:
};

#endif // GAMESTATEMENU_H
