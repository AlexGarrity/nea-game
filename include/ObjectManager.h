/**     Alex Garrity, 2017      **/

#ifndef OBJECTMANAGER_H
#define OBJECTMANAGER_H

#include "GameObject.h"

#include <map>

class ObjectManager {
public:
    static void UpdateObjects();
    static void DrawObjects();


protected:
private:
    static std::map <std::string, GameObject*> objectMap;
};

#endif // OBJECTMANAGER_H
