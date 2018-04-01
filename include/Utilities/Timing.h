#ifndef TIMING_H
#define TIMING_H

#include <SFML/System/Clock.hpp>

class Timing {
public:
    static void Update();

    static float deltaTime;
protected:

private:
    static sf::Clock clock;
};

#endif // TIMING_H
