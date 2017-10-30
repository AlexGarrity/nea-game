#ifndef ENGINE_H
#define ENGINE_H

#include "WindowManager.h"
#include "ObjectManager.h"
#include "StateManager.h"
#include "NetworkManager.h"

class Engine
{
public:
    Engine();
    void Start(short x, short y, short depth, const char name[]);

protected:

private:
    void GameLoop();
};

#endif // ENGINE_H
