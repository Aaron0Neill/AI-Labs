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
        m_alien(t_alien)
    {

    }

    virtual void onEnter()=0;

    virtual void update(sf::Time t_dt) = 0;
    
    virtual void onExit()=0;
protected:
    Alien* m_alien;
};
#include "Alien.h"
#endif