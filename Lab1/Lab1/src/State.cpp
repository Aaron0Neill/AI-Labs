#include "State.h"

void State::moveToTarget(sf::Vector2f t_target, sf::Time t_dt)
{
    if (VectorSquaredDistance(m_alien->m_velocity) > m_maxSpeed * m_maxSpeed)
    {
        m_alien->m_velocity = getUnitVec(m_alien->m_velocity) * m_maxSpeed;
    }

    m_alien->m_velocity += t_target * t_dt.asSeconds() * m_acceleration;
}