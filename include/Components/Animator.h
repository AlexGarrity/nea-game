/**     Alex Garrity, 2017      **/

#ifndef ANIMATOR_H
#define ANIMATOR_H

/**
    The animator handles playing animations for one agent.
    This includes tracking running time, and being given animations
    to play by the agent
**/


class Animator {
public:
    Animator();
    virtual ~Animator();

    void Update();

    bool PlayAnimation(std::string animationName);
protected:
private:
    std::map<std::string, Animation*> animationMap;


};

#endif // ANIMATOR_H
