#include "State.h"

void State::moveToTarget(sf::Time t_dt)
{
    m_alien->m_velocity += (*m_target - m_alien->m_position) * t_dt.asSeconds() * m_acceleration;

    if (VectorSquaredDistance(m_alien->m_velocity) > m_maxSpeed * m_maxSpeed)
    {
        m_alien->m_velocity = getUnitVec(m_alien->m_velocity) * m_maxSpeed;
    }
}