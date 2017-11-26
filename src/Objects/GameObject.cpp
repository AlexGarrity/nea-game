#include "GameObject.h"

GameObject::GameObject()
{

}

GameObject::~GameObject()
{
    //
}

sf::Sprite& GameObject::GetSprite()
{
    return sprite;
}

sf::Vector2f GameObject::GetPosition()
{
    return position;
}

void GameObject::SetPosition(float x, float y)
{
    position.x = x;
    position.y = y;
}

void GameObject::SetPosition(sf::Vector2f pos)
{
    position = pos;
}
