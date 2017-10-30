#include "UIManager.h"

std::vector<UIElement*> UIManager::UIelements;

void UIManager::Update()
{
    for (int i = 0; i < UIelements.size(); i++)
    {
        UIelements[i]->Update();
        WindowManager::Draw(UIelements[i]->GetSprite());
    }
}
