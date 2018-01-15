#include "ResourceManager.h"

std::map<const char*, std::unique_ptr<sf::Texture>> ResourceManager::textureMap;

void ResourceManager::Load(const char* filePath, const char* texName)
{
    //Create a unique pointer to a new texture
    std::unique_ptr<sf::Texture> texture(new sf::Texture());
    //Load a texture from a file
    texture->loadFromFile(filePath);
    //Add the texture to the texture map
    textureMap.insert(std::make_pair(texName, std::move(texture)));
}

sf::Texture& ResourceManager::Get(const char* texName)
{
    //Create an auto, and set it to the value of the texture found at texName
    auto tex = textureMap.find(texName);
    //Return the texture pointer
    return *tex->second;
}

void ResourceManager::LoadManifest(const char* filePath)
{
    std::ifstream fileReader (filePath, std::ifstream::in);


    while (fileReader.good()) {
        std::string currentLine = fileReader.getline();

        //If the line is worth reading...
        if (currentLine.size() > 3) {
            XMLTypes currentTag = GetTag();

        }
    }
    fileReader.close();
}


XMLTypes ResourceManager::GetTag()
{
    unsigned short startMarker;
    unsigned short endMarker;
    for (unsigned int i = 1; i < currentLine.size(); i++) {
        if (currentLine[i] == '<') {
            startMarker = i+1;
        }
        if (currentLine[i] == '>')
            endMarker = i - 1;
        break;      //Prematurely end because the tag has been found
    }
    std::string markerText = substr(startMarker, endMarker - startMarker);
    if (markerText == "Type") {
        return Type;
    } else if (markerText == "Filepath") {
        return Filepath;
    }
    return Invalid;
}
