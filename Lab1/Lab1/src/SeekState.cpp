#include "SeekState.h"

SeekState::SeekState(Alien* t_alien) : 
    State(t_alien)
{

}

//****************************************

SeekState::~SeekState()
{
}

//****************************************

void SeekState::onEnter()
{
    printf("Entering Seek State\n");
    if (m_alien != nullptr)
        m_alien->m_body.setColor(sf::Color::Magenta);

    if (m_alien->m_target == nullptr)
        printf("Error with seek state! Error: No target found\n");
}

//****************************************

void SeekState::update(sf::Time t_dt)
{
    if (m_alien->m_target != nullptr)
    {
        moveToTarget(getUnitVec(*m_alien->m_target - m_alien->m_position), t_dt);
    }
}

//****************************************

void SeekState::onExit()
{
    if (m_alien != nullptr)
        m_alien->m_body.setColor(sf::Color(100,100,100,100));   
    printf("Exiting Seek State\n");
}