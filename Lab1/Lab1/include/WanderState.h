#ifndef WANDER_STATE_INCLUDE
#define WANDER_STATE_INCLUDE

#include "State.h"

class WanderState : public State
{
public:
    WanderState(sf::Vector2f* t_myVelocity);
    virtual ~WanderState();

    virtual void onEnter();

    virtual void update(sf::Time t_dt)override;

    virtual void onExit();
private:
    sf::Vector2f* m_velocity;
    float m_wanderOffset;
    float m_wanderRadius;
    float m_wanderRate;
    float m_wanderOrientation;
    float m_maxAcc;
};
#endif