#include "UITextField.h"

UITextField::UITextField (sf::Vector2f position, sf::Vector2u dimensions, sf::Texture &texture, std::string dText, sf::Font &font, UIElement *parent) : UIElement (position, dimensions, texture, parent)
{
    fieldText.setCharacterSize (dimensions.y * 0.8f);
    fieldText.setFont (font);
    fieldText.setFillColor (sf::Color::Green);
    fieldText.setPosition (position);

    defaultText = dText;
}

UITextField::~UITextField()
{
    //dtor
}

void UITextField::OnHover()
{
    char enteredText = WindowManager::GetInput();

    if (fieldText.getFillColor() != sf::Color::Red) {
        fieldText.setFillColor (sf::Color::Red);
    }

    if (enteredText == 8) {
        if (currentText.size() > 0) {
            currentText.pop_back();
        }
    }
    else {
        if (enteredText > 32 && enteredText < 127) {
            currentText.push_back (enteredText);
        }
    }
}


void UITextField::Update (sf::Vector2f mousePosition, bool click)
{
    if (fieldText.getFillColor() != sf::Color::Green) {
        fieldText.setFillColor (sf::Color::Green);
    }

    if (mousePosition.x > GetPosition().x && mousePosition.x < (GetPosition().x + GetSize().x) ) {
        if (mousePosition.y > GetPosition().y && mousePosition.y < (GetPosition().y + GetSize().y) ) {
            OnHover();
        }
    }

    if (currentText == "") {
        fieldText.setString (defaultText);
    }
    else {
        fieldText.setString (currentText);
    }
}

sf::Drawable *UITextField::GetSprite()
{
    return &fieldText;
}

std::string UITextField::GetText()
{
    return currentText;
}
