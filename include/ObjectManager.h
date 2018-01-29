/**     Alex Garrity, 2018      **/

#ifndef OBJECTMANAGER_H
#define OBJECTMANAGER_H

#include "GameObject.h"
#include "NetworkManager.h"
#include "WindowManager.h"
#include "ResourceManager.h"

#include <map>
#include <cctype>
#include <sstream>

class ObjectManager {
public:
    static void UpdateObjects();
    static void DrawObjects();

    static void NetworkUpdate();
    static void CreateObject(GameObject *object, char UUID[16]);


protected:
private:
    static void ParseInstruction(NetworkInstruction n);
    template <typename T>
    std::vector<T> SeparateProperties(std::string details);

    static std::map <std::string, GameObject*> objectMap;
};

#endif // OBJECTMANAGER_H
