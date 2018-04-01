#include "Level.h"

Level::Level()
{
    //ctor
}

Level::~Level()
{
    //dtor
}

unsigned char *Level::FindNextTile (std::string &level)
{
    unsigned char values[2] = {000, 000};
    values[0] = level.at (0);
    values[1] = level.at (1);
    level.erase (level.begin(), level.begin() + 6);
    return values;
}

void Level::LoadLevel (std::string &level)
{
    unsigned char *tile = nullptr;

    for (unsigned char x = 0; x < 50; x++) {
        for (unsigned char y = 0; y < 50; y++) {
            tile = FindNextTile (level);
            tiles[x][y].Set (tile[0], tile[1]);
        }
    }

    delete tile;
}

Tile* Level::GetTiles()
{
    return *tiles;
}
