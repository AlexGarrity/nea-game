#ifndef LEVEL_H
#define LEVEL_H

#include <SFML/System/Vector2.hpp>

#include <string>

class Tile {
public:
    Tile() {};
    Tile (unsigned char id, unsigned char p)
    {
        tileId = id;
        tileProperty = p;
    }

    void Set (unsigned char id, unsigned char p = 'n')
    {
        tileId = id;
        tileProperty = p;
    }

    unsigned char tileId;
    unsigned char tileProperty;
};


class Level {
public:
    Level();
    virtual ~Level();

    void LoadLevel (std::string &level);
    Tile *GetTiles();
protected:

private:
    unsigned char *FindNextTile (std::string &level);

    Tile tiles[50][50];

};

#endif // LEVEL_H
