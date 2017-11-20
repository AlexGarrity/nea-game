#include "Engine.h"

/**
    Main Function -
        Creates and instance of the engine, then checks if it's started correctly
        If it starts correctly, then the process will run and return 0 at the end
        If it doesn't, the process returns 17 (this is a dumb arbitrary value that means nothing)
**/

/**
    Note that this project doesn't work when run through Code::Blocks
    It must be run through the executable or command line for enhanced logging
    Failure to do so will mean that no textures load and the entire game
    just displays 'PLACE HOLDER'
**/

int main()
{
    Engine engine;
    if (!engine.Start(1280, 720, 32, "Window")) {
        return 17;
    } else {
        return 0;
    }
}
