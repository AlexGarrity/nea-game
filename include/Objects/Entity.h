#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/System/Vector2.hpp>

#include <cstring>

#include "Statblock.h"
#include "GameObject.h"

class Entity : public GameObject
{

enum EntityState { Idle, Moving, Attacking, Fleeing };

public:
    Entity (const char *c);
    Entity (float xPos, float yPos, unsigned char worldX, unsigned char worldY, unsigned char *c, Stats &s, Vitals &v);

    virtual void Update();
    unsigned char* GetWorldPosition();

    char* GetUUID();
    void SetUUID(const char *c);

    Vitals &GetVitals();
    Stats &GetStats();

protected:

private:
    Stats stats;
    Vitals vitals;

    EntityState currentState;

    sf::Vector2f cellPosition;
    unsigned char worldPosition[2];

    char UUID[16];
};

#endif // ENTITY_H
