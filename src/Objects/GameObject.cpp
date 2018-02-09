/**     Alex Garrity, 2018      **/

#include "GameObject.h"

GameObject::GameObject()
{
    //ctor
}

GameObject::~GameObject()
{
    //dtor
}

sf::Sprite &GameObject::GetSprite()
{
    return sprite;
}

void GameObject::Update ()
{

}

void GameObject::Translate (float dX, float dY)
{
    position.x += dX;
    position.y += dY;
}
