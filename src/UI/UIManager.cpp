/**     Alex Garrity, 2018      **/

#include "UIManager.h"

std::vector<UIElement*> UIManager::UIelements;
sf::View UIView;

void UIManager::Update()
{
    sf::Vector2f mousePosition = sf::Mouse::getPosition (WindowManager::GetWindow() );

    //For each UIElement in the vector...
    for (int i = 0; i < UIelements.size(); i++)
    {
        //Call the Update function of UIElement, i
        UIelements[i]->Update();
    }
}
