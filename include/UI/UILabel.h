#ifndef UILABEL_H
#define UILABEL_H

#include <SFML/Graphics/Text.hpp>
#include <string>

#include "UIElement.h"

class UILabel : virtual public UIElement
{
    public:
        UILabel(std::string label, unsigned char size);
        virtual ~UILabel();

        void SetText(std::string text);
        sf::Text &GetText();
        sf::Drawable &GetSprite();

    protected:
        sf::Text text;

    private:


};

#endif // UILABEL_H
