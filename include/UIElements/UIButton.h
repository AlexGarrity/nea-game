#ifndef UIBUTTON_H
#define UIBUTTON_H

#include "UIElement.h"
#include <functional>

// For some reason, someone decided that there shouldn't just be an implicit pointer to an instance attached to void* variables, so I have to use std::function.
// Don't use function pointers for member functions...


class UIButton : public UIElement {
public:
    UIButton (sf::Vector2f position, sf::Vector2u dimensions, sf::Texture &texture, std::function<void()> call, UIElement *parent = nullptr);
    virtual ~UIButton();

    void OnRelease();
protected:

private:
    std::function<void()> callback; //Function pointer to what should be called when the function is called
};

#endif // UIBUTTON_H
