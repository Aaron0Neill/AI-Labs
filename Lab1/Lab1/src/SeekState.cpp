#include "SeekState.h"

SeekState::SeekState(Alien* t_alien) : 
    State(t_alien)
{
    m_alien->m_heading = 0;
}

//****************************************

SeekState::~SeekState()
{
}

//****************************************

void SeekState::onEnter()
{
    std::cout << "Entering Seek State\n";
    if (m_alien != nullptr)
        m_alien->m_body.setColor(sf::Color::Magenta);
}

//****************************************

void SeekState::update(sf::Time t_dt)
{
    if (m_alien->m_target != nullptr)
    {
        float cross = CrossProduct(m_alien->m_velocity, *m_alien->m_target - m_alien->m_position);
        if (cross > m_maxTurnRadius * t_dt.asSeconds() || cross < -m_maxTurnRadius * t_dt.asSeconds())
        {
            m_alien->m_heading += (cross > 0) ? m_maxTurnRadius * t_dt.asSeconds() : -m_maxTurnRadius * t_dt.asSeconds();
            m_alien->m_velocity = sf::Vector2f{ cosf(m_alien->m_heading), sinf(m_alien->m_heading) };
        }
    }
    else
    {
        printf("Error with seek state! Error: No target found\n");
    }
}

//****************************************

void SeekState::onExit()
{
    std::cout << "Exiting Seek State\n";
}