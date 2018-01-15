#ifndef ANIMATION_H
#define ANIMATION_H

#include "Time.h"       //Used in timing animations for smooth playback

#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Sprite.hpp>

class Animation {
public:
    Animation(sf::Sprite &entitySprite);
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
