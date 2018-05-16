#ifndef UIELEMENT_H
#define UIELEMENT_H

#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>

#include "WindowManager.h"

class UIElement {
public:
    UIElement (sf::Vector2f pos, sf::Vector2u dim, sf::Texture &texture, UIElement* par = nullptr);
    virtual ~UIElement();

    virtual void Update (sf::Vector2f mousePosition, bool click);

    virtual sf::Drawable *GetSprite();
    sf::Vector2f GetPosition();
    sf::Vector2u GetSize();

protected:
    virtual void OnPress();
    virtual void OnRelease();
    virtual void OnHover();

private:
    bool heldDown = false;

    sf::Sprite sprite;
    sf::Drawable *drawable;
    sf::Texture texture;

    UIElement *parent = nullptr;
    sf::Vector2f position;
    sf::Vector2u dimensions;
};

#endif // UIELEMENT_H
