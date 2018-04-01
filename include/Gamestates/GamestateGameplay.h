#ifndef GAMESTATEGAMEPLAY_H
#define GAMESTATEGAMEPLAY_H

#include "Gamestate.h"


class GamestateGameplay : public Gamestate {
public:
    GamestateGameplay();
    virtual ~GamestateGameplay();

    void Input();
    void Update();
    void Draw ();
protected:

private:
};

#endif // GAMESTATEGAMEPLAY_H
