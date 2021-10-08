#include "WanderState.h"

WanderState::WanderState(Alien* t_alien) : 
    State(t_alien),
    m_targetCtr(5),
    m_targetRadius(10),
    m_waitTime(4)
{

}

//****************************************

WanderState::~WanderState()
{

}

//****************************************

void WanderState::onEnter()
{
    m_targetHeading = m_alien->m_heading;
    m_alien->m_body.setColor(sf::Color::Cyan);
    m_alien->m_velocityScaler = 25;
}

//****************************************

void WanderState::update(sf::Time t_dt)
{
    m_waitTime -= t_dt.asSeconds();
    if (m_waitTime <= 0)
    {
        sf::Vector2f wanderOffsetPt = m_alien->m_position + (m_alien->m_velocity * m_targetCtr);
        float randDeg = static_cast<float>(rand() % 360);
        randDeg = Deg2Rad(randDeg);
        sf::Vector2f targetPt = (sf::Vector2f{cosf(randDeg), sinf(randDeg)} * m_targetRadius) + wanderOffsetPt;
        m_targetHeading =  getPositiveHeading(targetPt- m_alien->m_position);
        m_waitTime = 6;
    }

    if (m_alien->m_heading > m_targetHeading + m_maxTurnRadius * t_dt.asSeconds() ||
        m_alien->m_heading < m_targetHeading - m_maxTurnRadius * t_dt.asSeconds())
    {
        if (m_alien->m_heading < m_targetHeading)
            m_alien->m_heading += m_maxTurnRadius * t_dt.asSeconds();
        else
            m_alien->m_heading -= m_maxTurnRadius * t_dt.asSeconds();

        m_alien->m_velocity = sf::Vector2f{ cosf(m_alien->m_heading)
        , sinf(m_alien->m_heading) };
    }
}

//****************************************

void WanderState::onExit()
{
    std::cout << "Exiting Wander State\n";
}