#include "GameObject.h"

GameObject::GameObject()
{
    //ctor
}

GameObject::~GameObject()
{
    //dtor
}

sf::Sprite& GameObject::GetSprite()
{
    return sprite;
}
