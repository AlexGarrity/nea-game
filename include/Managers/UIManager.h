#ifndef UIMANAGER_H
#define UIMANAGER_H

#include <string>
#include <map>

#include <SFML/Window/Mouse.hpp>

#include "WindowManager.h"

#include "UIElement.h"
#include "UIButton.h"
#include "UIImage.h"
#include "UITextField.h"
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
