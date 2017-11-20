#include "ResourceManager.h"

std::map<const char*, std::unique_ptr<sf::Texture>> ResourceManager::textureMap;

void ResourceManager::Load(const char* filePath, const char* texName)
{
    std::unique_ptr<sf::Texture> texture(new sf::Texture());
    texture->loadFromFile(filePath);
    textureMap.insert(std::make_pair(texName, std::move(texture)));
}

sf::Texture& ResourceManager::Get(const char* texName)
{
    auto tex = textureMap.find(texName);
    return *tex->second;
}


