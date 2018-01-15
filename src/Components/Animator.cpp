/**     Alex Garrity, 2018      **/

#include "Animator.h"

Animator::Animator()
{

}

void Animator::Update()
{

}

bool Animator::PlayAnimation(std::string animationName)
{
    const auto &animation = animationMap.find(animationName);
    if (animation != nullptr) {
        return true;
    }
}
