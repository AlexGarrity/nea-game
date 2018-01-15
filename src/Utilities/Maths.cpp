#include "Maths.h"

// Only returns squared magnitude as there's no point rooting it
float Maths::Pythagoras(float deltaX, float deltaY)
{
    //Return the sum of deltaX squared and deltaY squared
    return pow(deltaX, 2) + pow(deltaY, 2);
}

float Maths::Pythagoras(sf::Vector2f o, sf::Vector2f t)
{
    //Calculate deltaX and deltaY by subtracting the target from the desination
    float deltaX = Absolute(t.x - o.x);
    float deltaY = Absolute(t.y - o.y);
    //Return the sum of deltaX squared and deltaY squared
    return pow(deltaX, 2) + pow(deltaY, 2);
}

template <class T>
T Maths::Pythagoras(T xA, T yA, T xB, T yB)
{
    //Calculate deltaX and deltaY by subtracting coordinate B from A
    T deltaX = Absolute(xB - xA);
    T deltaY = Absolute(yB - yA);
    //Return the sum of deltaX squared and deltaY squared
    return pow(deltaX, 2) + pow(deltaY, 2);
}

float Maths::Absolute(float x)
{
    //If the given value is less than 0
    if (x < 0) {
        //Return the value multiplied by -1
        return x * -1;
    }
    //If that's not true, return the actual value
    return x;
}

int Maths::Absolute(int x)
{
    //If the given value is less than 0
    if (x < 0) {
        //Return the value multiplied by -1
        return x * -1;
    }
    //If that's not true, return the actual value
    return x;
}

