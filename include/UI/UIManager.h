/**     Alex Garrity, 2018      **/

#ifndef UIMANAGER_H
#define UIMANAGER_H

#include "NetworkManager.h"
#include "WindowManager.h"

#include <vector>
#include <functional>

#include "UIElement.h"
#include "UILabel.h"
#include "UIButton.h"


/**
    The UI Manager handles all forms of UI updates, inputs, and changes.
    It has few functions as they're mainly in the UI elements themselves.
**/

class UIManager {

    enum UILayouts { Splash, Login, Gameplay, GameMenu };

public:
    static void Update();
    static void LoadUI(UILayouts layout);
    static void ClearUI();

protected:
private:
    static std::vector<UIElement*> UIElements;
    static sf::View UIView;
};

#endif // UIMANAGER_H
