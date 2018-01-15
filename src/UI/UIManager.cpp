/**     Alex Garrity, 2017      **/

#include "UIManager.h"

std::vector<UIElement*> UIManager::UIelements;
sf::View UIView;

void UIManager::Update()
{
    //For each UIElement in the vector...
    for (int i = 0; i < UIelements.size(); i++) {
        //Call the Update function of UIElement, i
        UIelements[i]->Update();
    }
}
