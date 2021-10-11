#ifndef ARRIVE_STATE_INCLUDE
#define ARRIVE_STATE_INCLUDE

#include "State.h"

class ArriveState : public State
{
public:
    ArriveState(Alien* t_alien);
    virtual ~ArriveState();

    virtual void onEnter()override;

    virtual void update(sf::Time t_dt)override;

    virtual void onExit()override;
private:
    float m_offset;
};
#endif