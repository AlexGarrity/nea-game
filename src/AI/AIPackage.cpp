#include "AIPackage.h"

AIPackage::AIPackage(Entity &agent)
{
    this->agent = &agent;
}

AIPackage::~AIPackage()
{
    //dtor
}

void AIPackage::Update()
{
    if (State.front() == Idle) {
        OnIdle();
    }

}

void AIPackage::OnAttack(Entity attacker)
{
    //Base AI attacks back when attacked
    switch (State.front()) {
    case Idle:

        break;
    case Moving:

        break;
    case Attacked:

        break;
    case MovingToTarget:

        break;
    case Attacking:

        break;
    }
}

void AIPackage::OnSpot(Entity target)
{
    //Base AI does nothing as it's passive
}

void AIPackage::OnIdle()
{
    //The AI will accept commands from the network manager whilst it's idle
}


bool AIPackage::ObjectInAttackRange()
{
    //Do Pythagoras to figure out distance to enemy
    if (Maths::Pythagoras(agent->GetPosition(), target->GetPosition()) < agent->GetRange()) {
        return true;
    }
    return false;
}
