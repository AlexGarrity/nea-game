/**     Alex Garrity, 2018      **/

#ifndef ENGINE_H
#define ENGINE_H

//Allows for multithreading.
//I'll try to scale this to appropriate hardware, such that 4-core CPUs take full advantage of it
//But that might not happen since it can lead to more issues than performance bonuses.
#include <thread>

#include "WindowManager.h"
#include "ObjectManager.h"
#include "StateManager.h"
#include "NetworkManager.h"
#include "ResourceManager.h"
#include "UIManager.h"
#include "Time.hpp"

/** Includes for testing, may remove later **/
#include "GameObject.h"
#include "Debug.h"
#include "Entity.h"

/** Declares functions and variables (but only functions in this case) **/

/**
    The Engine class is essentially a container for a bunch of management
    classes and general update functions.  It does very little processing of its
    own.
**/

class Engine {
public:
    bool Start ( short x, short y, short depth, const char name[] );

protected:

private:
    void GameLoop();
    void TestLoop();

    void NetworkUpdate();
    void GraphicsUpdate();
};

#endif // ENGINE_H
