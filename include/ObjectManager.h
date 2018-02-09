/**     Alex Garrity, 2018      **/

#ifndef OBJECTMANAGER_H
#define OBJECTMANAGER_H

#include "GameObject.h"
#include "Entity.h"

#include "NetworkManager.h"
#include "WindowManager.h"
#include "ResourceManager.h"

#include <map>
#include <cctype>
#include <sstream>

class ObjectManager
{
public:
    static void UpdateObjects();
    static void DrawObjects();

    static void NetworkUpdate();
    static void CreateObject (GameObject *object, char UUID[16]);
    static void CreateEntity (Entity *entity);


protected:
private:
    static void ParseInstruction (NetworkInstruction n);
    template <typename T>
    static std::vector<T> SeparateProperties (std::string details);

    static std::map <char[16], GameObject*> objectMap;
    static std::map <char[16], Entity*> entityMap;

    static std::map<char[16], GameObject*>::iterator itObject;
    static std::map<char[16], Entity*>::iterator itEntity;
};

#endif // OBJECTMANAGER_H
