/**     Alex Garrity, 2017      **/

#ifndef UIMANAGER_H
#define UIMANAGER_H

#include "WindowManager.h"
#include <vector>

#include "UIElement.h"


class UIManager {
public:
    static void Update();
protected:
private:
    static std::vector<UIElement*> UIelements;
    static sf::View UIView;
};

#endif // UIMANAGER_H
