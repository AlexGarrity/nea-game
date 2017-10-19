#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include <fstream>
#include <map>
#include <SFML/Graphics/Image.hpp>

class ResourceManager
{
public:
    static void LoadImage(const char* fileName);
    static void LoadManifest(const char* filePath);

protected:

private:
    static std::map<const char*, sf::Image> imageMap;
};

#endif // RESOURCEMANAGER_H
