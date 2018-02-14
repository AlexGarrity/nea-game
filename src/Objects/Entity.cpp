#include "Entity.h"

Entity::Entity ( std::string id )
{
    Stat statSword ( 0, 1 );
    Stat statHammer ( 0, 1 );
    Stat statAxe ( 0, 1 );
    Stat statBow ( 0, 1 );
    Stat statMagic ( 0, 1 );

    Stats s ( statSword, statHammer, statAxe, statBow, statMagic );
    stats = s;
    UUID = id;
}

Entity::Entity ( float xPos, float yPos, unsigned char worldX, unsigned char worldY, std::string id, Stats &s, Vitals &v ) : stats ( s ), vitals ( v )
{
    cellPosition.x = xPos;
    cellPosition.y = yPos;
    worldPosition[0] = worldX;
    worldPosition[1] = worldY;
    UUID = id;
}

void Entity::Update ()
{
    switch ( currentState ) {
    case Idle: {
        //Do nothing as the NPC is idle
        //Maybe some background processing will be done here
    }
    break;
    case Moving: {
        //Use A* pathing to find the optimum path to the destination
    }
    break;
    case Attacking: {
        //Check if attack cooldown is 0, check if target is in range
        //Apply one damage calculation's worth of damage to the target
    }
    break;
    case Fleeing: {
        //Go in the opposite direction to the target
    }
    break;
    }
}

unsigned char* Entity::GetWorldPosition()
{
    return worldPosition;
}

std::string Entity::GetUUID()
{
    return UUID;
}

void Entity::SetUUID ( const std::string c )
{
    UUID = c;
}

Vitals &Entity::GetVitals()
{
    return vitals;
}

Stats &Entity::GetStats()
{
    return stats;
}
