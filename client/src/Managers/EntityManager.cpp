#include "Managers/EntityManager.h"

std::map<std::string, Entity*> EntityManager::entityMap;

void EntityManager::Update()
{
    NetworkInstruction *instruction = nullptr;
    unsigned char type;
    std::string subject;
    std::string details;
    std::map<std::string, Entity*>::iterator entity;


    while (!NetworkManager::downQueue.empty() ) {
        instruction = NetworkManager::downQueue.front();
        NetworkManager::downQueue.pop();
        type = instruction->type;
        subject = instruction->subject;
        details = instruction->details;

        switch (type) {
        case (10) : {   //Case 1-0, Create a new Entity
            Entity* e = new Entity (*ResourceManager::GetEntity (details) );
            entityMap.insert (std::make_pair (subject, e) );
        }
        break;

        case (11) : {   //Case 1-1, Destroy an entity
            entity = entityMap.find (subject);

            if (entity != entityMap.end() ) {
                entityMap.erase (entity);
            }
        }
        break;

        case (12) : {   //Case 1-2, Set an entity's next point to pathfind to
            entity = entityMap.find (subject);

            if (entity != entityMap.end() ) {
                if (entity->second != nullptr) {
                    //entity->second->GetAI()->PathTo(1,1)
                }
            }
        }
        break;

        case (13) : {   //Case 1-3, Update entity vitals

        }
        break;

        case (14) : {   //Case 1-4, Something else

        }
        break;


        break;
        }
    }

    delete instruction;
}


void EntityManager::AddEntity (Entity *e, std::string key)
{
    entityMap.insert (std::make_pair (key, e) );
}

Entity* EntityManager::GetEntity (std::string key)
{
    auto entity = entityMap.find (key);
    return entity->second;
}

void EntityManager::RemoveEntity (std::string key)
{
    entityMap.erase (key);
}
