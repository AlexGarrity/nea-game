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

/**
    In the future, I would like to multithread the application such that physics,   [Physics is done on the server, not client]
    networking, and graphics are processed separately.
    There are a few complications at the minute, but I think I can do it
    using some stacks, queues, mutexes, and lots of keyboard mashing.

    Actually, it's easier than I planned it as being...
**/

int main()
{
    Engine e;
    if (!e.Start(1280, 720, 32, "Window")) {
        return 17;
    } else {
        return 0;
    }
}
