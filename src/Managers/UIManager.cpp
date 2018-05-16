#include "UIManager.h"

std::map<std::string, UIElement*> UIManager::uiElements;
std::map<std::string, UIElement*>::iterator UIManager::it = uiElements.begin() ;

void UIManager::AddElement (std::string key, UIElement *element)
{
    uiElements.insert (std::make_pair(key, element));
}

void UIManager::RemoveElement(std::string key)
{
    it = uiElements.find(key);
    if (it != uiElements.end()) {
        uiElements.erase(it);
    }
}

void UIManager::ClearElements()
{
    uiElements.clear();
}

void UIManager::Update()
{
    sf::Vector2i mousePositionAsInteger = sf::Mouse::getPosition();
    sf::Vector2f mousePosition(mousePositionAsInteger.x, mousePositionAsInteger.y);

    bool click = sf::Mouse::isButtonPressed(sf::Mouse::Button::Left);

    for (it = uiElements.begin(); it != uiElements.end(); ++it) {
        it->second->Update(mousePosition, click);
    }
}

void UIManager::Draw()
{

    for (it = uiElements.begin(); it != uiElements.end(); ++it) {
        WindowManager::Draw(it->second->GetSprite());
    }
}
