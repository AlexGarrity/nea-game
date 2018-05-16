#ifndef UITEXTFIELD_H
#define UITEXTFIELD_H

#include "UIElement.h"

#include <SFML/Graphics/Text.hpp>


class UITextField : public UIElement
{
    public:
        UITextField(sf::Vector2f position, sf::Vector2u dimensions, sf::Texture &texture, std::string dText, sf::Font &font, UIElement *parent);
        virtual ~UITextField();

        sf::Drawable *GetSprite();

        void OnHover();
        void Update(sf::Vector2f mousePosition, bool click);

        std::string GetText();

    protected:

    private:

        sf::Text fieldText;

        std::string defaultText;
        std::string currentText;
};

#endif // UITEXTFIELD_H
