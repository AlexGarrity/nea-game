/**     Alex Garrity, 2017      **/

#include "Time.h"

sf::Clock Time::clock;
float Time::deltaTime;

void Time::Update()
{
    //Set the value of deltaTime to the clock restart
    //Returns as seconds such that deltaTime is a floating point decimal
    deltaTime = clock.restart().asSeconds();
}

/*
    Why use deltaTime:
        deltaTime is the time it takes the computer to process and render a frame
        It's also sometimes known as frame time.

        deltaTime is useful for making things such as movement optically correct
        (ie. the character will move at their speed, but only the speed that they would cover in
         the time it took to complete an update cycle)

        This is mostly used for movement, but has some other applications for exact timings such
        as animation durations.


    How I implement deltaTime:
        My implementation is fairly generic when using the SFML library.  SFML has a class
        known as a clock.
        Every update, the clock is reset, and the value it reached is returned to the deltaTime
        variable.
        This variable is then globally accessible as it's a public static.


    Alternatives:
        None.
        I think.
*/
