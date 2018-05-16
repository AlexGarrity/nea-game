#ifndef UIIMAGE_H
#define UIIMAGE_H

#include "UIElement.h"


class UIImage : public UIElement {
public:
    UIImage (sf::Vector2f position, sf::Vector2u dimensions, sf::Texture &texture, UIElement *parent = nullptr);
    virtual ~UIImage();

    void Update (sf::Vector2f mousePosition, bool click);
protected:

private:
};

#endif // UIIMAGE_H
