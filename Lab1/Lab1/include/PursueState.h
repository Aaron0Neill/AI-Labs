#ifndef PURSUE_STATE_INCLUDE
#define PURSUE_STATE_INCLUDE

#include "State.h"

class PursueState : public State
{
public:
    PursueState(Alien* t_alien);
    virtual ~PursueState();

    virtual void onEnter()override;

    virtual void update(sf::Time t_dt)override;

    virtual void onExit()override;
private:
};
#endif