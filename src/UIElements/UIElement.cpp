#include "UIElement.h"

UIElement::UIElement (sf::Vector2f pos, sf::Vector2u dim, sf::Texture &tex, UIElement *par)
{
    if (par != nullptr) {
        position = par->GetPosition() + pos;
        dimensions = dim;
    }
    else {
        position = pos;
        dimensions = dim;
    }

    texture = tex;
    sprite.setTexture (texture);
    sprite.setPosition (pos);
    drawable = &sprite;
}

UIElement::~UIElement()
{
    delete parent;
    delete drawable;
}

void UIElement::Update (sf::Vector2f mousePosition, bool click)
{
    if (mousePosition.x > position.x && mousePosition.x < position.x + dimensions.x) {
        if (mousePosition.y > position.y && mousePosition.y < position.y + dimensions.y) {
            if (click) {
                if (!heldDown) {
                    heldDown = true;
                    OnPress();
                }
            }
            else if (heldDown) {
                OnRelease();
                heldDown = false;
            }
            else {
                OnHover();
            }
        }
    }
}

sf::Drawable *UIElement::GetSprite()
{
    return &sprite;
}

void UIElement::OnHover()
{

}

void UIElement::OnPress()
{

}

void UIElement::OnRelease()
{

}


sf::Vector2f UIElement::GetPosition()
{
    return position;
}

sf::Vector2u UIElement::GetSize()
{
    return dimensions;
}
