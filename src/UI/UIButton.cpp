#include "UIButton.h"

UIButton::UIButton (std::function<void() > f)
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
    if (edge == false)
    {
        func();
    }
}

void UIButton::OnRelease()
{
    if (edge == true)
    {
        func();
    }
}

void UIButton::OnValueChange()
{

}
