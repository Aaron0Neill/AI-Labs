#include "WanderState.h"

WanderState::WanderState(Alien* t_alien) : 
    State(t_alien),
    m_wanderOffset(5),
    m_wanderRadius(10),
    m_wanderRate(1),
    m_maxAcc(50),
    m_wanderWait(4)
{

}

WanderState::~WanderState()
{

}

void WanderState::onEnter()
{
    m_targetHeading = m_alien->m_heading;
    m_alien->getSprite().setColor(sf::Color::Cyan);
    m_alien->m_velocityScaler = 25;
}

void WanderState::update(sf::Time t_dt)
{
    m_wanderWait -= t_dt.asSeconds();
    if (m_wanderWait <= 0)
    {
        sf::Vector2f wanderOffsetPt = m_alien->m_position + (m_alien->m_velocity * m_wanderOffset);
        int randDeg = rand() % 360;
        randDeg = Deg2Rad(randDeg);
        sf::Vector2f targetPt = (sf::Vector2f{cosf(randDeg), sinf(randDeg)} * m_wanderRadius) + wanderOffsetPt;
        m_targetHeading =  getHeading(targetPt- m_alien->m_position);
        m_wanderWait = 4;
        std::cout << "Target: " << m_targetHeading << std::endl;
        std::cout << "Current: " << m_alien->m_heading << std::endl;
    }

    if (m_alien->m_heading > m_targetHeading + m_wanderRate * t_dt.asSeconds() ||
        m_alien->m_heading < m_targetHeading - m_wanderRate * t_dt.asSeconds())
    {
        if (m_alien->m_heading < m_targetHeading)
            m_alien-> m_heading += m_wanderRate * t_dt.asSeconds();
        else
            m_alien->m_heading -= m_wanderRate * t_dt.asSeconds();

        m_alien->m_velocity = sf::Vector2f{cosf(m_alien->m_heading)
        , sinf(m_alien->m_heading)};
    }
}

void WanderState::onExit()
{
    std::cout << "Exiting Wander State\n";
}