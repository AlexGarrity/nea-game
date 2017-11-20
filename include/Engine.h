#ifndef ENGINE_H
#define ENGINE_H

#include "WindowManager.h"
#include "ObjectManager.h"
#include "StateManager.h"
#include "NetworkManager.h"
#include "ResourceManager.h"

/** Includes for testing, remove later **/
#include "GameObject.h"
#include "Debug.h"

/** Declares functions and variables (but only functions in this case) **/

class Engine
{
public:
    Engine();
    bool Start(short x, short y, short depth, const char name[]);

protected:

private:
    void GameLoop();
    void TestLoop();
};

#endif // ENGINE_H
