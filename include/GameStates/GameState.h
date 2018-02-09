/**     Alex Garrity, 2018      **/

#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "NetworkManager.h"
#include "ObjectManager.h"
#include "ResourceManager.h"
#include "WindowManager.h"
#include "UIManager.h"
#include "Settings.h"

class GameState
{
public:
    virtual void Input() =0;
    virtual void Update() =0;
    virtual void Draw() =0;

protected:

private:
};

#endif // GAMESTATE_H
