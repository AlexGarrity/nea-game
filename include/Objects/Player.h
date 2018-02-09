#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"

class Player : public Entity
{
public:
    Player (float xPos, float yPos, unsigned char worldX, unsigned char worldY, unsigned char id[16], PlayerStats &s, Vitals &v);
    virtual ~Player();

protected:

private:
};

#endif // PLAYER_H
