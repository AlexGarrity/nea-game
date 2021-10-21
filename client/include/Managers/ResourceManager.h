#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H


#include <string>
#include <map>
#include <vector>
#include <fstream>
#include <sstream>

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Font.hpp>

#include "Entity/Entity.h"

struct ManifestNode {
    std::string attributeName;
    std::map<std::string, std::string> attributeValues;

    void AddValue(std::string aName, std::string aValue) {
        attributeValues.insert(std::make_pair(aName, aValue));
    }
};

class ManifestParser {
public:
    ManifestParser (std::string filepath);
    ~ManifestParser();

    void Parse ();

private:
    void ParseLine(std::string line);

    std::string filepath;
    unsigned int indentationLevel = 0;

};

class ResourceManager {
public:
    static Entity *GetEntity (std::string entityName);
    static sf::Texture &GetTexture (std::string textureName);
    static sf::Font &GetFont();

    static void Initialise();

protected:

private:
    static bool ParseEntity (std::string declaration);
    static bool LoadEntity (Entity* entity, std::string entityName);
    static bool LoadTexture (std::string filepath, std::string textureName);

    static bool LoadFromManifest (std::string filePath);

    static std::map<std::string, Entity*> entityMap;
    static std::map<std::string, sf::Texture*> textureMap;
    static sf::Font font;
};

#endif // RESOURCEMANAGER_H
