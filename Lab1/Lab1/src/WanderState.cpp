#include "WanderState.h"

WanderState::WanderState(sf::Vector2f* t_myVelocity) : 
    m_velocity(&(*t_myVelocity)), 
    m_wanderOffset(5),
    m_wanderRadius(1),
    m_wanderRate(15),
    m_maxAcc(50)
{

}

WanderState::~WanderState()
{

}

void WanderState::onEnter()
{
    std::cout << "Entering Wander State\n";
}

void WanderState::update(sf::Time t_dt)
{
}

void WanderState::onExit()
{
    std::cout << "Exiting Wander State\n";
}