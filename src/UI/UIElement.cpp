#include "UIElement.h"

void UIElement::Update()
{
    if (sf::Mouse::getPosition().x > position.x && sf::Mouse::getPosition().x < (position.x + sprite.getLocalBounds().width))
    {
        if (sf::Mouse::getPosition().y > position.y && sf::Mouse::getPosition().y < (position.y + sprite.getLocalBounds().height))
        {
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                OnPress();
                heldDown = true;
            }
            else if (!sf::Mouse::isButtonPressed(sf::Mouse::Left) && heldDown == true)
            {
                OnRelease();
                heldDown = false;
            }
            else
            {
                OnHover();
            }
        }
    }
}

sf::Sprite& UIElement::GetSprite()
{
    return sprite;
}
