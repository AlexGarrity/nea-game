/**     Alex Garrity, 2018      **/

#include "Animation.h"

Animation::Animation(sf::Sprite &entitySprite)
{
    sprite = &entitySprite;
    frameTime = animationTime / frameCount;
}

Animation::~Animation()
{
    //dtor
}

void Animation::Update()
{
    elapsedTime += Time::deltaTime;
    const sf::Vector2i sheetSize = sprite->getTexture()->getSize();
    sf::IntRect textureRect = sprite->getTextureRect();

    if (currentFrame == 0) {
        textureRect = sf::IntRect(0, 0, textureSize.x, textureSize.y);
    }

    while (elapsedTime < animationTime && currentFrame <= frameCount) {
        textureRect.left += textureSize.x;
        if (textureRect.left + textureSize.x > sheetSize.x) {
            textureRect.left = 0;
            textureRect.top += textureRect.height;
        }
        elapsedTime -= frameTime;
    }
    sprite->setTextureRect(textureRect);
}
