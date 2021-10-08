#ifndef STATE_INCLUDE
#define STATE_INCLUDE

#include <SFML/Graphics.hpp>
#include <iostream>
#include "MathUtils.h"

class Alien;

class State
{
public:
    State(Alien* t_alien) : 
        m_alien(t_alien),
        m_maxTurnRadius(1.0f),
        m_targetHeading(0)
    {

    }

    virtual void onEnter()=0;

    virtual void update(sf::Time t_dt) = 0;
    
    virtual void onExit()=0;

protected:
    Alien* m_alien;
    float m_maxTurnRadius; // max amount the alien can turn
    float m_targetHeading; // heading to the new target
};


#include "Alien.h"
#endif