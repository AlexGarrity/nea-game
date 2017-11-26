#include "Entity.h"

Entity::Entity(sf::Texture texture, float xPos, float yPos, float h, float r, float s)
{
    texture = texture;
    position = sf::Vector2f(xPos, yPos);
    sprite.setPosition(position);
    sprite.setTexture(texture);
    health = h;
    range = r;
    speed = s;
}

Entity::~Entity()
{

}

void Entity::Update()
{

}

void Entity::SetHealth(float h)
{
    if (h > 0) {
        health = h;
    } else {
        health = 1.0;
    }
}

void Entity::SetSpeed(float s)
{
    if (s >= 0) {
        speed = s;
    } else {
        speed = 1.0;
    }
}

void Entity::SetRange(float r)
{
    if (r > 0) {
        range = r;
    } else {
        range = 1.0;
    }
}

float Entity::GetHealth()
{
    return health;
}

float Entity::GetSpeed()
{
    return speed;
}

float Entity::GetRange()
{
    return range;
}
