#include "UILabel.h"

UILabel::UILabel(std::string buttonText, unsigned char buttonSize) : UIElement(sf::Vector2f())
{
    text.setString(buttonText);
    text.setCharacterSize(buttonSize);
}

UILabel::~UILabel()
{
    //dtor
}

sf::Drawable &UILabel::GetSprite ()
{
    return text;
}

sf::Text &UILabel::GetText () {
    return text;
}
