#ifndef OBJECTMANAGER_H
#define OBJECTMANAGER_H

#include <map>
#include <string>
/*
    Really wanted to avoid using string, but I can't find any other way that the map will work
    aside from making some sort of structure, which is likely less efficient
*/

#include "WindowManager.h"
#include "GameObject.h"
#include "ResourceManager.h"

class ObjectManager
{
public:
    static void UpdateObjects();

    static void CreateObject(std::string textureName, float x, float y);
    static void AddObject(GameObject* object, std::string id);
    static void RemoveObject(std::string);

protected:

private:
    static std::map<std::string, GameObject*> objectList;

    /*
        Whilst a map may seem like a strange choice of container considering this is just a long list of objects,
        it makes networking considerably easier as the server only has to send the object ID, and its new position
        (or whatever other detail is required to be sent)
    */
};

#endif // OBJECTMANAGER_H
