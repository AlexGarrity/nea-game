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
