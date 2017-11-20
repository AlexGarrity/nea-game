#include "GameObject.h"

GameObject::GameObject(sf::Texture tex, float xPos, float yPos)
{
    texture = tex;
    position = sf::Vector2f(xPos, yPos);
    sprite.setPosition(position);
    sprite.setTexture(texture);
}

GameObject::~GameObject()
{
    //dtor
}

sf::Sprite& GameObject::GetSprite()
{
    return sprite;
}
