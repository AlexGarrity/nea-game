#include "ResourceManager.h"

std::map<const char*, sf::Image> ResourceManager::imageMap;

void ResourceManager::LoadImage(const char* fileName)
{
    sf::Image image;
    image.loadFromFile(fileName);
    imageMap[fileName] = image;
}

void ResourceManager::LoadManifest(const char* fileName)
{

}
