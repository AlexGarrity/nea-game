#include "ObjectManager.h"

// Forward declared as private static within a class
std::map<std::string, GameObject*> ObjectManager::objectList;

// Iterates through all objects in the map and calls the update method
// After an object is updated, it's drawn
void ObjectManager::UpdateObjects()
{
    for (std::map<std::string, GameObject*>::iterator x = objectList.begin(); x != objectList.end(); ++x) {
        x->second->Update();
        WindowManager::Draw(x->second->GetSprite());
    }
}

void ObjectManager::CreateObject(std::string textureName, float x, float y)
{
    // AddObject();     Put ref to object created as argument
}

// Adds an object to the map at the specified position
void ObjectManager::AddObject(GameObject* object, std::string id)
{
    objectList.insert(std::make_pair(id, object));
    // Has some stupid error because it doesn't like the pair...
}

// Removes the object with the specified id from the list, hence deleting it
void ObjectManager::RemoveObject(std::string id)
{
    objectList.erase(id);
}
