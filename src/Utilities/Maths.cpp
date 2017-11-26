#include "Maths.h"

float Maths::Pythagoras(float deltaX, float deltaY)
{
    float x2;
    x2 = pow(deltaX, 2);
}

float Maths::Pythagoras(sf::Vector2f o, sf::Vector2f t)
{
    float deltaX = Absolute(t.x - o.x);
    float deltaY = Absolute(t.y - o.y);
    return sqrt(pow(deltaX, 2) + pow(deltaY, 2));
}
/*
float Maths::Pythagoras(float deltaX, float deltaY) {
    return sqrt(pow(deltaX, 2) + pow(deltaY, 2));
}
*/
float Maths::Pythagoras(float xA, float yA, float xB, float yB)
{
    float deltaX = Absolute(xB - xA);
    float deltaY = Absolute(yB - yA);
    return sqrt(pow(deltaX, 2) + pow(deltaY, 2));
}

float Maths::Absolute(float x)
{
    if (x < 0) {
        return x * -1;
    }
    return x;
}

int Maths::Absolute(int x)
{
    if (x < 0) {
        return x * -1;
    }
    return x;
}
