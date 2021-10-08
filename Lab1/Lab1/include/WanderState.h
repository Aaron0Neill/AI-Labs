#ifndef WANDER_STATE_INCLUDE
#define WANDER_STATE_INCLUDE

#include "State.h"
#include <iostream>

class WanderState : public State
{
public:
    WanderState(Alien* t_alien);
    virtual ~WanderState();

    virtual void onEnter();

    virtual void update(sf::Time t_dt)override;

    virtual void onExit();
private:
    float m_wanderWait;
    float m_wanderOffset;
    float m_wanderRadius;
    float m_wanderRate;
    float m_wanderOrientation;
    float m_maxAcc;
    float m_targetHeading;
};
#endif