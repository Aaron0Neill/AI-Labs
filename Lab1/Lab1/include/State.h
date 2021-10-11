#ifndef STATE_INCLUDE
#define STATE_INCLUDE

#include <SFML/Graphics.hpp>
#include <iostream>
#include "MathUtils.h"
#include <cstdio>

class Alien;

class State
{
public:
    State(Alien* t_alien) : 
        m_alien(t_alien),
        m_acceleration(.5f),
        m_maxSpeed(1.5f)
    {

    }

    virtual void onEnter()=0;

    virtual void update(sf::Time t_dt) = 0;
    
    virtual void onExit()=0;

protected:

    virtual void moveToTarget(sf::Vector2f t_target, sf::Time t_dt);

    Alien* m_alien;

    float m_maxSpeed;
    float m_acceleration;
};
#include "Alien.h"
#endif