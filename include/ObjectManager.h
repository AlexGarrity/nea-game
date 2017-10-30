#ifndef OBJECTMANAGER_H
#define OBJECTMANAGER_H

#include <map>
#include <iterator>

#include "WindowManager.h"
#include "GameObject.h"

class ObjectManager
{
public:
    static void UpdateObjects();

    static void CreateObject(GameObject* object, char id[4]);
    static void RemoveObject(char id[4]);

protected:

private:
    static std::map<char[4], GameObject*> objectList;
};

#endif // OBJECTMANAGER_H
