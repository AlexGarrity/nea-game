/**     Alex Garrity, 2018      **/

#include "UIManager.h"

std::vector<UIElement*>  UIManager::UIElements;
sf::View UIView;

void UIManager::Update()
{
    sf::Vector2i mousePosition = sf::Mouse::getPosition ( WindowManager::GetWindow() );

    //For each UIElement in the vector...
    for ( unsigned int i = 0; i < UIElements.size(); i++ ) {
        //Call the Update function of UIElement, i
        UIElements[i]->Update ( mousePosition );
        WindowManager::Draw(UIElements[i]->GetSprite());
    }
}

void UIManager::LoadUI(UILayouts layout)
{
    switch (layout)
    {
        case Login:
        {
            std::function <void () > func = std::bind(&NetworkManager::Login, "test", "test");
            UIElement *button = new UIButton(func, sf::Vector2f(0,0))
            UIElements.push_back();
        }
        break;
        case Gameplay:
        {

        }
        break;
        case GameMenu:
        {

        }
        break;
        case Splash:
        {

        }
        break;
    }
}

void UIManager::ClearUI()
{
    std::vector<UIElement*>::swap ( UIElements );
}
