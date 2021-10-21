#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "Managers/NetworkManager.h"
#include "Managers/UIManager.h"
#include "Managers/EntityManager.h"
#include "Managers/ResourceManager.h"
#include "Managers/WindowManager.h"
#include "Managers/StateManager.h"

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
