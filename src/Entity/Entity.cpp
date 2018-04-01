#include "Entity.h"

Entity::Entity (sf::Texture &tex, sf::Vector2f pos)
{
    this->setTexture (tex);
    this->setPosition (pos);
}

Entity::Entity (Entity &e)
{
    this->setPosition (e.getPosition() );
    this->setTexture (*e.getTexture() );
}

Entity::~Entity()
{
    //dtor
}


void Entity::Translate (float dX, float dY)
{
    sf::Vector2f currentPosition = this->getPosition();
    currentPosition += sf::Vector2f (dX, dY);
    this->setPosition (currentPosition);
}

void Entity::Translate (sf::Vector2f delta)
{
    sf::Vector2f currentPosition = this->getPosition();
    currentPosition += delta;
    this->setPosition (currentPosition);
}
