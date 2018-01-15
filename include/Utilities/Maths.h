/**     Alex Garrity, 2017      **/

#ifndef MATHS_H
#define MATHS_H

#include <cmath>
#include "SFML/System/Vector2.hpp"

/**
    Extension of the cmath library with some higher level features like
    pythagoras and...
**/

class Maths {
public:
    template <class T>
    static T Pythagoras(T xA, T yA, T xB, T yB);        //Pythagoras two sets of coordinates
    static float Pythagoras(float deltaX, float deltaY);                    //Pythagoras for pre-computer deltaX and deltaY
    static float Pythagoras(sf::Vector2f origin, sf::Vector2f target);      //Pythagoras for two vector sets of coordinates

    static float Absolute (float x);        //Absolute functions returns magnitude of value
    static int Absolute (int x);            //Above, but for integers rather than floats

protected:
private:
};

#endif // MATHS_H
