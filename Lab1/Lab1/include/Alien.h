#ifndef ALIEN_H
#define ALIEN_H

#include "Entity.h"
#include <functional>
#include "WanderState.h"

enum class AiStates{
    NONE = -1,
    WANDER,
    SEEK,
    ARRIVE,
    FLEE
};

class Alien : public Entity
{
public:
    Alien(std::string const& t_filename);
    ~Alien();

    virtual void setState(AiStates const& t_state);

    virtual void update(sf::Time t_dt)override;

private:
    AiStates m_currentState;

    State* m_stateMovement;
};
#endif