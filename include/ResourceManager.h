/**     Alex Garrity, 2018      **/

#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include <map>
#include <memory>
#include <fstream>
#include <iostream>
#include <string>

#include <SFML/Graphics/Texture.hpp>

#include "GameObject.h"
#include "Entity.h"

enum XMLTypes { Resource, Type, FilePath, Invalid };
enum ResourceTypes { Graphic, SFX, Music, GUI };


/**
    Holds the data for one resource: what type of resource it is and where it's stored.
**/

struct Resource {
    ResourceTypes type;
    std::string filePath;
    std::string GenerateName();
};

/**
    The Resource Manager handles the reading of manifests, such that resources such as sounds
    and graphics can be loaded into the program.  After that, it handles giving resources to
    objects that require them.
**/

class ResourceManager {
public:
    //Function to load textures given a filepath and a texture name
    static void Load ( const char* filePath = nullptr, const char* texName = nullptr);

    static Entity *GetEntity ( std::string entityName = "");
    //Function to return textures
    static sf::Texture &Get ( const char* texName = nullptr);
    //Function which will load a list of files from a manifest and save them as resources
    static void LoadManifest ( const char* filePath = nullptr);

    static XMLTypes GetTag ( std::string currentLine = "");

protected:

private:
    static std::map<std::string, std::unique_ptr<sf::Texture>> textureMap;
    static std::map<std::string, std::unique_ptr<Entity*>> entityMap;
};

#endif // RESOURCEMANAGER_H
