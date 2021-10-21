#include "UIElements/UIButton.h"

UIButton::UIButton (sf::Vector2f position, sf::Vector2u dimensions, sf::Texture &texture, std::function<void()> call, UIElement *parent) : UIElement (position, dimensions, texture, parent)
{
    callback = call;
}

UIButton::~UIButton()
{

}

void UIButton::OnRelease()
{
    callback();
    std::cout << "Ran callback function" << std::endl;
}
