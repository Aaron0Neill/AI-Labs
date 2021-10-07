#include "include/Alien.h"

Alien::Alien(std::string const& t_filename) :
    Entity(t_filename),
    m_currentState(AiStates::NONE),
    m_stateMovement(nullptr)
{

}

Alien::~Alien()
{

}

void Alien::setState(AiStates const& t_state)
{
    if (m_currentState != t_state)
    {
        m_currentState = t_state;
        if (m_stateMovement != nullptr)
            delete m_stateMovement;

        switch (m_currentState)
        {
        case AiStates::WANDER:
            m_stateMovement = new WanderState(&m_velocity);
            break;
        case AiStates::SEEK:
            break;
        case AiStates::ARRIVE:
            break;
        case AiStates::FLEE:
            break;
        }
    }
}

void Alien::update(sf::Time t_dt)
{
    Entity::update(t_dt);
    m_stateMovement->update(t_dt);
}
