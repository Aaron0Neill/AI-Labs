#include "WanderState.h"
#include <iostream>

WanderState::WanderState(sf::Vector2f* t_myVelocity) : 
    m_velocity(&(*t_myVelocity))
{

}

WanderState::~WanderState()
{

}

void WanderState::update(sf::Time t_dt)
{
    std::cout << "WanderState Update\n";
}