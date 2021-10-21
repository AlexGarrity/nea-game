#ifndef UIMANAGER_H
#define UIMANAGER_H

#include <string>
#include <map>

#include <SFML/Window/Mouse.hpp>

#include "WindowManager.h"

#include "UIElements/UIElement.h"
#include "UIElements/UIButton.h"
#include "UIElements/UIImage.h"
#include "UIElements/UITextField.h"
//#include "UIText.h"     //As of yet unimplemented

class UIManager {
public:
    static void Update();
    static void Draw();

    static void AddElement (std::string, UIElement *element);
    static void RemoveElement(std::string key);
    static void ClearElements();

protected:

private:
    static std::map<std::string, UIElement*> uiElements;
    static std::map<std::string, UIElement*>::iterator it;
};

#endif // UIMANAGER_H
