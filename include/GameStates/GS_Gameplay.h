#ifndef GS_GAMEPLAY_H
#define GS_GAMEPLAY_H

#include <GameState.h>

/**
    Gameplay class represents the game being played.  This means that the network manager will
    be actively sending and receiving data, as well as enabling and drawing the majority of the
    GUI and full user input
**/

class GS_Gameplay : public GameState {
public:
    void Input();
    void Update();
    void Draw();
protected:
private:
};

#endif // GS_GAMEPLAY_H
