#ifndef MAP_H
#define MAP_H

#include <SFML/Graphics/VertexArray.hpp>

#include "Level.h"
#include "Settings.h"

class Map {
public:
    Map();
    virtual ~Map();

    void LoadLevel ( Level &level, unsigned int levelX = 50, unsigned int levelY = 50, unsigned int tileSize = 32, unsigned int tileSetX = 1024, unsigned int tileSetY = 1024 );

protected:

private:
    sf::VertexArray vertexArray;
};

#endif // MAP_H
