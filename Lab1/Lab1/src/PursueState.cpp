#include "PursueState.h"

PursueState::PursueState(Alien* t_alien) : 
	State(t_alien)
{
    m_name = "Pursue";
}

//****************************************

PursueState::~PursueState()
{
}

//****************************************

void PursueState::onEnter()
{
    printf("Entering Pursue State\n");

    if (m_alien != nullptr)
        m_alien->m_body.setColor(sf::Color::Red);

    if (m_alien->m_target == nullptr)
        printf("Error with seek state! Error: No target found\n");
}

//****************************************

void PursueState::update(sf::Time t_dt)
{
    float alienSpeed = VectorSquaredDistance(m_alien->m_velocity);
    sf::Vector2f projectedPt = *m_alien->m_target + 
        (getUnitVec(*m_alien->m_playerVelo) * VectorDistance(*m_alien->m_target - m_alien->m_position) / ((alienSpeed != 0) ? alienSpeed : 1));

    moveToTarget(getUnitVec(projectedPt - m_alien->m_position), t_dt);
}

//****************************************

void PursueState::onExit()
{
    printf("Exiting Pursue State\n");

    if (m_alien != nullptr)
        m_alien->m_body.setColor(sf::Color(100,100,100,100));
}
