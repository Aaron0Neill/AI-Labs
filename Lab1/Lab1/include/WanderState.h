#ifndef WANDER_STATE_INCLUDE
#define WANDER_STATE_INCLUDE

#include "State.h"

class WanderState : public State
{
public:
    WanderState(sf::Vector2f* t_myVelocity);
    virtual ~WanderState();

    virtual void update(sf::Time t_dt)override;
private:
    sf::Vector2f* m_velocity;
};
#endif