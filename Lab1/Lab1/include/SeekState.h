#ifndef SEEK_STATE_INCLUDE
#define SEEK_STATE_INCLUDE

#include "State.h"

class SeekState : public State
{
public:
    SeekState(sf::Vector2f* t_target);
    virtual ~SeekState();

    virtual void onEnter()override;

    virtual void update(sf::Time t_dt)override;

    virtual void onExit()override;
private:
    sf::Vector2f* m_target;
};
#endif