#include "UIButton.h"

UIButton::UIButton (std::function<void(void)> f, sf::Vector2f pos, std::string buttonText, unsigned char textSize) : UIElement(pos), UILabel(buttonText, textSize)
{
    func = f;
    text.setPosition(pos);
    position = pos;
}

UIButton::UIButton(std::function<void(void)> f, sf::Vector2f pos) : UIElement(pos), UILabel("", 0)
{
    func = f;
}

UIButton::~UIButton()
{
    //dtor
}

void UIButton::OnHover()
{

}

void UIButton::OnPress()
{

}

void UIButton::OnRelease()
{
    func();
}
