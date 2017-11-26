#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Texture.hpp>

class GameObject
{
public:
    GameObject();
    virtual ~GameObject();

    virtual sf::Sprite& GetSprite();
    virtual void Update() =0;

    virtual sf::Vector2f GetPosition();
    virtual void SetPosition(float x, float y);
    virtual void SetPosition(sf::Vector2f pos);

protected:
    sf::Sprite sprite;
    sf::Texture texture;
    sf::Vector2f position;

private:

};

#endif // GAMEOBJECT_H
