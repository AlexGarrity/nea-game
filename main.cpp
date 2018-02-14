/**     Alex Garrity, 2018      **/

#include "Engine.h"

/**
    Main Function -
        Creates and instance of the engine, then checks if it's started correctly
        If it starts correctly, then the process will run and return 0 at the end
        If it doesn't, the process returns 17 (this is a dumb arbitrary value that means nothing)
**/

int main()
{
    Engine e;

    if ( !e.Start ( 1280, 720, 32, "Window" ) ) {
        return 17;
    } else {
        return 0;
    }
}
