#ifndef MATHS_H
#define MATHS_H

/** Custom maths utility class **/
#include <cmath>

#include "SFML/System/Vector2.hpp"

class Maths
{
public:
    static float Pythagoras(float xA, float yA, float xB, float yB);     //Pythagoras given four points
    static float Pythagoras(float deltaX, float deltaY);    //Pythagoras for pre-computer deltaX and deltaY
    static float Pythagoras(sf::Vector2f origin, sf::Vector2f target);

    static float Absolute (float x);
    static int Absolute (int x);

protected:
private:
};

#endif // MATHS_H
