#include "Player.h"

Player::Player (float xPos, float yPos, unsigned char worldX, unsigned char worldY, unsigned char id[16], PlayerStats &s, Vitals &v) : Entity (xPos, yPos, worldX, worldY, id, s, v)
{

}

Player::~Player()
{
    //dtor
}
