#include "ObjectManager.h"

std::map<char[4], GameObject*> ObjectManager::objectList;

void ObjectManager::UpdateObjects()
{
    std::map<char[4], GameObject*>::iterator x;
    for (x = objectList.begin(); x!= objectList.end(); x++) {
        WindowManager::Draw(x->GetSprite());
    }
}

void ObjectManager::CreateObject(GameObject* object, char id[4])
{
    objectList[id] = object;
}

void ObjectManager::RemoveObject(char id[4])
{
    objectList.erase(id);
}
