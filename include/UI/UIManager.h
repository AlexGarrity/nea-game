#ifndef UIMANAGER_H
#define UIMANAGER_H

#include "WindowManager.h"
#include <vector>

#include "UIElement.h"


class UIManager
{
public:
    static void Update();
protected:
private:
    static std::vector<UIElement*> UIelements;
};

#endif // UIMANAGER_H
