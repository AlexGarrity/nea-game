#ifndef ENTITYMANAGER_H
#define ENTITYMANAGER_H

#include "NetworkManager.h"
#include "ResourceManager.h"

#include "Entity.h"

#include <map>
#include <string>

class EntityManager {
public:
    static void Update();

    static void AddEntity (Entity *e, std::string key);
    static Entity* GetEntity (std::string key);
    static void RemoveEntity (std::string key);

protected:

private:
    static std::map<std::string, Entity*> entityMap;
};

#endif // ENTITYMANAGER_H
