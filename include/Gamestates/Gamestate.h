#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "NetworkManager.h"
#include "UIManager.h"
#include "EntityManager.h"
#include "ResourceManager.h"
#include "WindowManager.h"
#include "StateManager.h"

class GamestateInitialise;
class GamestateLogin;
class GamestateMenu;
class GamestateGameplay;

class Gamestate {
public:
    Gamestate();
    virtual ~Gamestate();

    virtual void Update() =0;
    virtual void Input() = 0;
    virtual void Draw () =0;

protected:

private:
};

#endif // GAMESTATE_H
