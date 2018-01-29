/**     Alex Garrity, 2018      **/

#ifndef ENTITY_H
#define ENTITY_H

#include "GameObject.h"
#include "Animator.h"

/**
    Entity describes an object that is 'living' which will be
    updated by the server and be 'alive' (as opposed to something like
    a barrel which is stationary and will always be in its set position)
**/


class Entity : public GameObject {
public:
    Entity();
    ~Entity();

protected:
    float health;
    float movementSpeed;

private:
};

#endif // ENTITY_H
