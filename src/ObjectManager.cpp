#include "ObjectManager.h"

std::vector<GameObject*> ObjectManager::objectList;

void ObjectManager::UpdateObjects()
{
    for (unsigned int i = 0; i < objectList.size(); i++)
    {
        //I'm a real programmer now.  I used a pointer...
        WindowManager::Draw(objectList[i]->GetSprite());
    }
}

void ObjectManager::CreateObject(GameObject* object)
{
    objectList.push_back(object);
}

void ObjectManager::RemoveObject(unsigned int index)
{
    objectList.erase(objectList.begin() + (index - 1));
}
