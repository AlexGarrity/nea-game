#ifndef OBJECTMANAGER_H
#define OBJECTMANAGER_H

#include <vector>
#include "WindowManager.h"
#include "GameObject.h"

class ObjectManager
{
public:
    static void UpdateObjects();

protected:

private:
    static std::vector<GameObject*> objectList;
};

#endif // OBJECTMANAGER_H
