#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/System/Vector2.hpp>

#include <string>

#include "Statblock.h"
#include "GameObject.h"

/**
    An entity is an object that is 'living'.  This generally means that it will move around
    and interact with other entities in the world, such as players.
**/

class Entity : public GameObject {

    enum EntityState { Idle, Moving, Attacking, Fleeing };

public:
    Entity ( std::string c );
    Entity ( float xPos, float yPos, unsigned char worldX, unsigned char worldY, std::string c, Stats &s, Vitals &v );

    virtual void Update();
    unsigned char* GetWorldPosition();

    std::string GetUUID();
    void SetUUID ( const std::string s );

    Vitals &GetVitals();
    Stats &GetStats();

protected:

private:
    Stats stats;
    Vitals vitals;

    EntityState currentState;

    sf::Vector2f cellPosition;
    unsigned char worldPosition[2];

    std::string UUID;
};

#endif // ENTITY_H
