#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics/Sprite.hpp>


class Entity : public sf::Sprite {
public:
    Entity (sf::Texture &texture, sf::Vector2f position);
    Entity (Entity &e);
    virtual ~Entity();

    void Translate (float deltaX, float deltaY);
    void Translate (sf::Vector2f delta);
    void SetPosition(sf::Vector2f position);

    void Path();

protected:

private:

};

#endif // ENTITY_H
