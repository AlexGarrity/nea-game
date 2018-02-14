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

/**
    The Object Manager handles updating and drawing all entities and object in
    existence (according to the client)
**/

class ObjectManager {
public:
    static void UpdateObjects();
    static void DrawObjects();

    static void NetworkUpdate();
    static void CreateObject ( GameObject *object, std::string UUID );
    static void CreateEntity ( Entity *entity );


protected:
private:
    static void ParseInstruction ( NetworkInstruction n );
    template <typename T>
    static std::vector<T> SeparateProperties ( std::string details );

    static std::map <std::string, GameObject*> objectMap;
    static std::map <std::string, Entity*> entityMap;

    static std::map<std::string, GameObject*>::iterator itObject;
    static std::map<std::string, Entity*>::iterator itEntity;
};

#endif // OBJECTMANAGER_H
