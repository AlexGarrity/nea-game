#include "ResourceManager.h"

std::map<std::string, Entity*> ResourceManager::entityMap;
std::map<std::string, sf::Texture*> ResourceManager::textureMap;


ManifestParser::ManifestParser (std::vector<std::string> &m)
{
    manifest = &m;
}

ManifestParser::~ManifestParser()
{
    delete manifest;
}

void ManifestParser::Parse ()
{
    std::string currentTag = "";
    std::string type = "";

    for (unsigned int i = 0; i < manifest->size(); i++) {
        currentTag = GetTag (manifest->at (i) );

        if (currentTag == "entity") {
            //Get the entity properties and create a new entity using them
            type = "entity";

        }
        else if (currentTag == "texture") {
            //Load using the provided filepath and name
            std::string filepath = "";
            std::string name = "";
            i++;

            while (currentTag != "/texture") {
                currentTag = GetTag (manifest->at (i) );

                if (currentTag == "") {

                }
            }

        }
        else if (currentTag == "manifest") {
            //Create a new manifest parser and parse
        }
    }
}

std::string ManifestParser::GetTag (std::string line)
{
    unsigned int startMarker = 0;
    unsigned int endMarker = 0;

    for (unsigned int i = 0; i < line.size(); i++) {
        if (line[i] == '<' && i != (line.size() - 2) ) {
            startMarker = i+ 1;
        }
        else if (line[i] == '>') {
            endMarker = i -1;
        }
    }

    if (endMarker > startMarker) {
        return "";
    }
    else {
        return line.substr (startMarker, endMarker - startMarker);
    }
}


Entity *ResourceManager::GetEntity (std::string entityName)
{
    std::map<std::string, Entity*>::iterator entity = entityMap.find (entityName);

    if (entity != entityMap.end() ) {
        return entity->second;
    }
    else {
        return nullptr;
    }
}

sf::Texture &ResourceManager::GetTexture (std::string textureName)
{
    std::map<std::string, sf::Texture*>::iterator texture = textureMap.find (textureName);

    if (texture != textureMap.end() ) {
        return *texture->second;
    }
    else {
        return *textureMap.at ("error_not_found");
    }
}


bool ResourceManager::LoadEntity (Entity* entity, std::string entityName)
{
    if (entity != nullptr) {
        entityMap.insert (std::make_pair (entityName, entity) );
        return true;
    }

    return false;
}

bool ResourceManager::LoadTexture (std::string filePath, std::string textureName)
{
    sf::Texture* tex;

    if (tex->loadFromFile (filePath) ) {
        textureMap.insert (std::make_pair (textureName, tex) );
        return true;
    }

    return false;
}

bool ResourceManager::LoadFromManifest (std::string filePath)
{
    std::ifstream fileReader (filePath, std::fstream::in);
    std::vector<std::string> manifest;
    std::string line = "";

    if (!fileReader.good() ) {
        return false;
    }

    while (fileReader.good() ) {
        std::getline (fileReader, line);
        manifest.push_back (line);
    }

    ManifestParser mParser (manifest);
    mParser.Parse();

    fileReader.close();
    return true;
}
