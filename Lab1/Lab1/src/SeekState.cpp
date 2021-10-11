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
    if (m_alien != nullptr)
        m_alien->m_body.setColor(sf::Color::Magenta);
    if (m_target == nullptr)
    {
        printf("Error with seek state! Error: No target found\n");
    }
}

//****************************************

void SeekState::update(sf::Time t_dt)
{
    if (m_alien->m_target != nullptr)
    {
        moveToTarget(t_dt);
    }
}

//****************************************

void SeekState::onExit()
{
    delete m_target;
    std::cout << "Exiting Seek State\n";
}