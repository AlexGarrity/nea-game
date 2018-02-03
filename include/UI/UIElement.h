/**     Alex Garrity, 2018      **/

#ifndef UIELEMENT_H
#define UIELEMENT_H

#include <functional>

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Window/Mouse.hpp>

class UIElement {
public:
    UIElement();
    void Update();
    sf::Sprite& GetSprite();
protected:
    virtual void OnPress() =0;
    virtual void OnRelease() =0;
    virtual void OnHover() =0;

    sf::Vector2f position;
    sf::Text text;
    sf::Sprite sprite;
    sf::Texture texture;

    bool heldDown = false;
    unsigned char value;
private:

};

#endif // UIELEMENT_H
