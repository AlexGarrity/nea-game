#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Texture.hpp>

class GameObject
{
public:
    /** Constructor -
        In accordance with the RIAA (Resoure Acquisition is Initialisation) idiom, textures are acquired at this point
        This also sets the object's position in 2D space, and assigns the two properties to the sprite
    **/
    GameObject(sf::Texture texture, float xPos, float yPos);

    /** Destructor -
        Not a lot happens here.
    **/
    virtual ~GameObject();

    sf::Sprite& GetSprite();
    virtual void Update() =0;

protected:

private:
    sf::Sprite sprite;
    sf::Texture texture;
    sf::Vector2f position;
};

#endif // GAMEOBJECT_H
