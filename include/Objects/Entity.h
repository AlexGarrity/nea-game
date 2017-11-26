#ifndef ENTITY_H
#define ENTITY_H

#include "GameObject.h"

class Entity : public GameObject
{
public:
    Entity(sf::Texture texture, float xPos, float yPos, float health, float range, float speed);
    virtual ~Entity();

    virtual void Update();

    virtual float GetHealth();
    virtual float GetSpeed();
    virtual float GetRange();

    virtual void SetHealth(float h);
    virtual void SetSpeed(float s);
    virtual void SetRange(float r);

protected:
    float health;
    float speed;
    float range;

private:
};

#endif // ENTITY_H
