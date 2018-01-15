#ifndef TIME_H
#define TIME_H

#include "SFML/System/Clock.hpp"


/**
    Custom time library grants access the timings like frame time
    and fixed update timings
**/

class Time {
public:
    static void Update();
    static float deltaTime;

protected:
private:
    static sf::Clock clock;
};

#endif // TIME_H
