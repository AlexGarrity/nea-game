#include "Entity.h"

Entity::Entity()
{
    //ctor
}

Entity::~Entity()
{
    //dtor
}

void Entity::Translate(float deltaX, float deltaY)
{
    position.x += deltaX;
    position.y += deltaY;
    sprite.setPosition(position);
}
