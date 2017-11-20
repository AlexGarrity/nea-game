#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include <map>
#include <memory>

#include <SFML/Graphics/Texture.hpp>

class ResourceManager
{
public:
    static void Load(const char* filePath, const char* texName);
    static sf::Texture &Get(const char* texName);

protected:

private:
    static std::map<const char*, std::unique_ptr<sf::Texture>> textureMap;
};

#endif // RESOURCEMANAGER_H
