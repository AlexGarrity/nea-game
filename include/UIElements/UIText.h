#ifndef UITEXT_H
#define UITEXT_H

#include "UIElement.h"

//Might implement this at some point
class UIText : public UIElement
{
    public:
        UIText();
        virtual ~UIText();

        sf::Drawable *GetSprite();
    protected:

    private:
};

#endif // UITEXT_H
