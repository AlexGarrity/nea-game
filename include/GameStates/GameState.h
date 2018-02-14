/**     Alex Garrity, 2018      **/

#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "NetworkManager.h"
#include "ObjectManager.h"
#include "ResourceManager.h"
#include "WindowManager.h"
#include "UIManager.h"
#include "Settings.h"

/**
    A gamestate is one state that the game can be in.  This could be paused, splash screen,
    playing, etc.  The class is almost exclusively pure virtual since it's pretty much just a class
    to inherit from for ease of calling functions.
**/

class GameState {
public:
    GameState();
    virtual ~GameState();

    virtual void Input() = 0;
    virtual void Update() = 0;
    virtual void Draw() = 0;

protected:

private:
};

#endif // GAMESTATE_H
