#ifndef UIBUTTON_H
#define UIBUTTON_H

#include <functional>

#include "UIElement.h"
#include "UILabel.h"

/**
    A button.  You can press it and it does whatever you want it to.
    Or it might not.  I, for one, welcome our new button overlords.
**/

class UIButton : public UIElement, UILabel {
public:
    UIButton(std::function<void(void)> f, sf::Vector2f pos, std::string buttonText, unsigned char textSize);
    UIButton(std::function<void(void)> f, sf::Vector2f pos);
    virtual ~UIButton();

    void OnPress();
    void OnHover();
    void OnRelease();

protected:

private:
    std::function<void() > func;
};

#endif // UIBUTTON_H
