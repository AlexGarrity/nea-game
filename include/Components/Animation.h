/**     Alex Garrity, 2018      **/

#ifndef ANIMATION_H
#define ANIMATION_H

#include "Time.hpp"       //Used in timing animations for smooth playback

#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Sprite.hpp>

/**
    An animation is a set of instructions for displaying a sequence of images in
    such and order that the user is fooled into thinking that something is moving.
    That chicken's not really moving, you just think it is...
**/

class Animation {
public:
    Animation ( sf::Sprite &entitySprite );
    virtual ~Animation();

    void Update();
protected:
private:

    float animationTime;
    float elapsedTime;
    float frameTime;

    unsigned short frameCount;
    unsigned short currentFrame;

    sf::Vector2i textureSize;
    sf::Sprite *sprite;
};

#endif // ANIMATION_H
