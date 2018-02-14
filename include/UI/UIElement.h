/**     Alex Garrity, 2018      **/

#ifndef UIELEMENT_H
#define UIELEMENT_H

#include <functional>

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Window/Mouse.hpp>

/**
    An item that fits into the Graphical User Interface.  No consoles over here (except
    for if you need more verbose logging).
    This is another class that's basically only used as a base for other classes.
**/

class UIElement {
public:

    UIElement( sf::Vector2f pos );
    virtual ~UIElement();

    void Update ( sf::Vector2i mousePosition );
    virtual sf::Drawable &GetSprite();
protected:
    virtual void OnPress();
    virtual void OnRelease();
    virtual void OnHover();

    sf::Vector2f position;
    sf::Sprite sprite;
    sf::Texture texture;

    bool heldDown = false;
    unsigned char value;
private:

};

#endif // UIELEMENT_H
