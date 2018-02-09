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

struct Resource
{
    ResourceTypes type;
    std::string filePath;

    std::string GenerateName()
    {
        unsigned short startMarker = 0;

        for (unsigned int i = filePath.size(); i > 0; i--)
        {
            if (filePath[i] == '/')
            {
                startMarker = i+1;
                break;
            }
        }

        std::string prefix;

        switch (type)
        {
        case Graphic:
            prefix = "gr_";
            break;

        case SFX:
            prefix = "se_";
            break;

        case Music:
            prefix = "mu_";
            break;

        case GUI:
            prefix = "ui_";
            break;
        }

        std::string internalName = prefix + filePath.substr (startMarker, filePath.size() - startMarker - 4);
        return internalName;            //Wouldn't let me do this with a single constructor for some reason...
    }
};

class ResourceManager
{
public:
    //Function to load textures given a filepath and a texture name
    static void Load (const char* filePath, const char* texName);

    static Entity &GetEntity (std::string entityName);
    //Function to return textures
    static sf::Texture &Get (const char* texName);
    //Function which will load a list of files from a manifest and save them as resources
    static void LoadManifest (const char* filePath);

    static XMLTypes GetTag (std::string currentLine);

protected:

private:
    static std::map<std::string, std::unique_ptr<sf::Texture>> textureMap;
    static std::map<std::string, std::unique_ptr<Entity*>> entityMap;
};

#endif // RESOURCEMANAGER_H
