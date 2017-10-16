#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Texture.hpp>

class GameObject
{
    public:
        /** Default constructor */
        GameObject();
        /** Default destructor */
        virtual ~GameObject();

        sf::Sprite& GetSprite();

    protected:

    private:
        sf::Sprite sprite;
        sf::Texture texture;
        sf::Vector2f position;
};

#endif // GAMEOBJECT_H
