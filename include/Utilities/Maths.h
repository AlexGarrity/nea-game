/**     Alex Garrity, 2018      **/

#ifndef MATHS_H
#define MATHS_H

#include <cmath>
#include "SFML/System/Vector2.hpp"

/**
    Extension of the cmath library with some higher level features like
    pythagoras and...
**/

class Maths
{
public:
    template <class T>
    static T Pythagoras (T xA, T yA, T xB, T yB);       //Pythagoras two sets of coordinates
    static float Pythagoras (float deltaX, float deltaY);                   //Pythagoras for pre-computer deltaX and deltaY
    static float Pythagoras (sf::Vector2f origin, sf::Vector2f target);     //Pythagoras for two vector sets of coordinates

    static float Absolute (float x);        //Absolute functions returns magnitude of value
    static int Absolute (int x);            //Above, but for integers rather than floats

    static float Pow (float base, unsigned char exponent);
    static int Pow (int base, unsigned char exponent);

    static float Mean (float *values, unsigned char argc);
    static int Mean (int *values, unsigned char arcg);

    static float Greatest (float *values, unsigned char argc);
    static int Greatest (int *values, unsigned char argc);

protected:
private:
};

#endif // MATHS_H
