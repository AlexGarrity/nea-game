#ifndef UIBUTTON_H
#define UIBUTTON_H

#include <UIElement.h>


class UIButton : public UIElement {
public:
    UIButton();
    virtual ~UIButton();

    void OnPress();
    void OnHover();
    void OnRelease();

protected:

private:
    std::function<void()> func;
    bool edge;  //Rising or falling
};

#endif // UIBUTTON_H
