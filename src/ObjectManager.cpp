/**     Alex Garrity, 2018      **/

#include "ObjectManager.h"

std::map <std::string, GameObject*> ObjectManager::objectMap;
std::map <std::string, Entity*> ObjectManager::entityMap;

std::map<std::string, GameObject*>::iterator ObjectManager::itObject;
std::map<std::string, Entity*>::iterator ObjectManager::itEntity;

void ObjectManager::UpdateObjects()
{
    for ( itEntity = entityMap.begin(); itEntity != entityMap.end(); ++itEntity ) {
        itEntity->second->Update();
    }
}

void ObjectManager::DrawObjects()
{
    for ( itEntity = entityMap.begin(); itEntity != entityMap.end(); ++itEntity ) {
        WindowManager::Draw ( itEntity->second->GetSprite() );
    }
}

void ObjectManager::NetworkUpdate()
{
    while ( NetworkManager::updateQueueDown.size() > 0 ) {
        NetworkInstruction currentInstruction = NetworkManager::updateQueueDown.front();
        NetworkManager::updateQueueDown.pop();
        ParseInstruction ( currentInstruction );
    }
}

void ObjectManager::ParseInstruction ( const NetworkInstruction n )
{
    unsigned char type = n.type;

    switch ( type ) {
    case 20: {
        Entity* ent = ResourceManager::GetEntity ( n.details );
        ent->SetUUID ( n.subject );
        CreateEntity ( ent );
        break;
    }

    case 21: {
        auto ent = entityMap.find ( n.subject );

        if ( ent != entityMap.end() ) {
            GameObject *obj = ent->second;
            std::vector<float> properties = SeparateProperties<float> ( n.details );
            obj->Translate ( properties[0], properties[1] );
        }

        break;
    }

    case 22: {
        auto ent = entityMap.find ( n.subject );

        if ( ent != entityMap.end() ) {
            std::vector<float> properties = SeparateProperties<float> ( n.details );
            ent->second->GetVitals();
        }

        break;
    }
    }
}

template <typename T>
std::vector<T> ObjectManager::SeparateProperties ( std::string details )
{
    unsigned short startMarker, endMarker;
    T property;

    std::vector<T> returnVector;
    std::stringstream sStream;

    if ( std::isdigit ( details[0] ) ) {
        startMarker = 0;
    }

    for ( unsigned int i = 0; i < details.size(); i++ ) {
        if ( details[i] == '|' ) {
            endMarker = i;
            sStream << details.substr ( 0, endMarker - startMarker );
            sStream >> property;
            returnVector.push_back ( property );
            startMarker = endMarker;
        }
    }
    return returnVector;
}

void ObjectManager::CreateEntity ( Entity* entity )
{
    entityMap.insert ( std::make_pair ( entity->GetUUID(), entity ) );
}

void ObjectManager::CreateObject ( GameObject *object, std::string UUID )
{
    objectMap.insert ( std::make_pair ( UUID, object ) );
}
