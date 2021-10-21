#include "UIElements/UIImage.h"

UIImage::UIImage (sf::Vector2f position, sf::Vector2u dimensions, sf::Texture &texture, UIElement *parent) : UIElement (position, dimensions, texture, parent)
{

}

UIImage::~UIImage()
{
    //dtor
}

void UIImage::Update (sf::Vector2f mousePosition, bool click)
{
    //Override to nothing to improve efficiency
}
