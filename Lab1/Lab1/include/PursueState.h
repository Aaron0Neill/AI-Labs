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

    virtual void addPlayerVelocity(sf::Vector2f* t_playerVelo) { m_playerVelo = t_playerVelo; };
private:
    sf::Vector2f* m_playerVelo;
};
#endif