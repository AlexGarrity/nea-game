/**     Alex Garrity, 2018      **/

#include "ObjectManager.h"

std::map <std::string, GameObject*> ObjectManager::objectMap;

void ObjectManager::UpdateObjects()
{
    std::map<std::string, GameObject*>::iterator it;
    for (it = objectMap.begin(); it != objectMap.end(); ++it) {
        it->second->Update();
        WindowManager::Draw(it->second->GetSprite());
    }
}

void ObjectManager::NetworkUpdate()
{
    while (NetworkManager::updateQueueDown.size() > 0) {
        NetworkInstruction currentInstruction = NetworkManager::updateQueueDown.front();
        NetworkManager::updateQueueDown.pop();
        ParseInstruction(currentInstruction);
    }
}

void ObjectManager::ParseInstruction(const NetworkInstruction n)
{
    unsigned char type = n.type;
    switch (type) {
    case 20: {
        GameObject* obj = &ResourceManager::GetEntity(n.details);
        //CreateObject(obj, n.subject);
        break;
    }
    case 21: {
        auto obj = objectMap.find(n.subject);
        if (obj != objectMap.end()) {
            std::vector<float> properties = SeparateProperties<float>(n.details);
            obj->second->Translate(properties[0], properties[1]);
        }
        break;
    }
    case 22: {
        auto obj = objectMap.find(n.subject);
        if (obj != objectMap.end()) {
            std::vector<float> properties = SeparateProperties<float>(n.details);
            obj->second->SetVitals(properties[0], properties[1], properties[2]);
        }
        break;
    }
    }
}

template <typename T>
std::vector<T> ObjectManager::SeparateProperties(std::string details)
{
    unsigned short startMarker, endMarker;
    std::vector<T> returnVector;
    if (std::isdigit(details[0])) {
        startMarker = 0;
    }
    for (unsigned int i = 0; i < details.size(); i++) {
        if (details[i] == '|') {
            endMarker = i;
            T property << details.substr(details.begin(), endMarker - startMarker);
            returnVector.push_back(property);
            startMarker = endMarker;
        }
    }
}

void ObjectManager::CreateObject(GameObject *object, char UUID[16])
{
    objectMap.insert(std::make_pair(UUID, object));
}
