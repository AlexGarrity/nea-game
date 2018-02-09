#include "Map.h"

Map::Map()
{
    //ctor
}

Map::~Map()
{
    //dtor
}

void Map::LoadLevel (Level &level, unsigned int levelX, unsigned int levelY, unsigned int tileSize, unsigned int tileSetX, unsigned int tileSetY)
{
    vertexArray.setPrimitiveType (sf::Quads);
    vertexArray.resize (levelX * levelY * 4);

    sf::Vertex *current = nullptr;

    unsigned int tileNumber = 0;
    unsigned int tileX = 0;
    unsigned int tileY = 0;

    for (unsigned int x = 0; x < levelX; ++x)
    {
        for (unsigned int y = 0; y < levelY; ++y)
        {
            current = &vertexArray[x + (y * levelY) * 4];
            tileNumber = x + (y * levelY);
            tileX = tileNumber % (tileSetX / tileSize);
            tileX = tileNumber % (tileSetY / tileSize);

            current[0].position = sf::Vector2f (x * tileSize, y * tileSize);
            current[1].position = sf::Vector2f ( (x+1) * tileSize, y * tileSize);
            current[2].position = sf::Vector2f ( (x+1) * tileSize, (y+1) * tileSize);
            current[3].position = sf::Vector2f (x * tileSize, (y+1) * tileSize);

            current[0].texCoords = sf::Vector2f (tileX * tileSize, tileY * tileSize);
            current[1].texCoords = sf::Vector2f ( (tileX + 1) * tileSize, tileY * tileSize);
            current[2].texCoords = sf::Vector2f ( (tileX + 1) * tileSize, (tileY + 1) * tileSize);
            current[3].texCoords = sf::Vector2f (tileX * tileSize, (tileY + 1) * tileSize);
        }
    }
}
