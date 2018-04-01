#ifndef UIMANAGER_H
#define UIMANAGER_H

#include <vector>

#include "UIElement.h"

class UIManager {
public:
    static void Update();
    static void Draw();

protected:

private:
    static std::vector<UIElement*> uiElements;
};

#endif // UIMANAGER_H
