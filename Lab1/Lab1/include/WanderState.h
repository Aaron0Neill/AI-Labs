#ifndef WANDER_STATE_INCLUDE
#define WANDER_STATE_INCLUDE

#include "State.h"
#include <iostream>

class WanderState : public State
{
public:
    WanderState(Alien* t_alien);
    virtual ~WanderState();

    virtual void onEnter()override;

    virtual void update(sf::Time t_dt)override;

    virtual void onExit()override;
private: 

    void updateTarget();
    float m_waitTime; // how long before the wanderer changes dir
    float m_targetCtr; // center of the circle for new heading
    float m_targetRadius; // radius of the circle
};
#endif