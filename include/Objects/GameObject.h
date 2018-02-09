/**     Alex Garrity, 2018      **/

#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Sprite.hpp>

/**
    A GameObject is something that exists in game, with a sprite and position on screen.
    It doesn't necessarily have AI processing or advanced features, it could be a building
    or a chicken prop
**/

class GameObject
{
public:
    GameObject();
    virtual ~GameObject();

    sf::Sprite &GetSprite();
    virtual void Update();
    virtual void Translate (float deltaX, float deltaY);

protected:
    sf::Vector2f position;
    sf::Texture texture;
    sf::Sprite sprite;

private:

};

#endif // GAMEOBJECT_H
