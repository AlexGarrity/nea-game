#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H


#include <string>
#include <map>
#include <vector>
#include <fstream>
#include <sstream>

#include <SFML/Graphics/Texture.hpp>

#include "Entity.h"

class ManifestParser {

public:
    ManifestParser (std::vector<std::string> &m);
    ~ManifestParser();

    void Parse ();

private:
    std::string GetTag (std::string line);

    std::vector<std::string> *manifest= nullptr;
};

class ResourceManager {
public:
    static Entity *GetEntity (std::string entityName);
    static sf::Texture &GetTexture (std::string textureName);

    static void Initialise();

protected:

private:
    static bool ParseEntity (std::string declaration);
    static bool LoadEntity (Entity* entity, std::string entityName);
    static bool LoadTexture (std::string filepath, std::string textureName);

    static bool LoadFromManifest (std::string filePath);

    static std::map<std::string, Entity*> entityMap;
    static std::map<std::string, sf::Texture*> textureMap;
};

#endif // RESOURCEMANAGER_H
