#ifndef UIELEMENT_H
#define UIELEMENT_H

#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Sprite.hpp>

class UIElement {
public:
    UIElement();
    virtual ~UIElement();

    virtual void Update (sf::Vector2f mousePosition) =0;

protected:

private:
};

#endif // UIELEMENT_H
