#ifndef AIPACKAGE_H
#define AIPACKAGE_H

#include "Entity.h"
#include "Maths.h"
#include <queue>

class AIPackage
{
public:
    AIPackage(Entity &agent);
    virtual ~AIPackage();

    void Update();

protected:
    Entity *agent;  //The object it's controlling
    GameObject *target;

    virtual void OnAttack(Entity attacker);
    virtual void OnSpot(Entity entity);
    virtual void OnIdle();

    void PathToPoint (sf::Vector2f target);
    void PathToObject (GameObject *target);

    bool ObjectInAttackRange ();
    bool ObjectInUseRange();

    enum AIState {Idle, Attacked, Attacking, Moving, MovingToTarget};
    std::queue<AIState> State;
private:

};

#endif // AIPACKAGE_H
