#ifndef LEVEL_H
#define LEVEL_H

#include <SFML/Graphics/Rect.hpp>

/**
    Level Properties:
        Every Level is 50x50, comprised of Nodes.
        One node is equivalent to 1m x 1m, for scaling purposes.
        A node has two properties: its type and its feature

**/

class Level {
public:
    Level();
    virtual ~Level();

    sf::Rect<int> rectangle;

protected:

private:
    unsigned char WorldX;
    unsigned char WorldY;

    //std::array<

};

#endif // LEVEL_H
