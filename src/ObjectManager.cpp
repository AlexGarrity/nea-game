#include "ObjectManager.h"

ObjectManager::ObjectManager()
{
    //ctor
}

ObjectManager::~ObjectManager()
{
    //dtor
}

void ObjectManager::UpdateObjects()
{
    for (unsigned int i = 0; i < objectList.size(); i++)
    {
        //I'm a real programmer now.  I used a pointer...
        window.draw(objectList[i]->GetSprite());
    }
}
