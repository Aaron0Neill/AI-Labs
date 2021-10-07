#include "include/Alien.h"

Alien::Alien(std::string const& t_filename) :
    Entity(t_filename),
    m_currentState(AiStates::NONE),
    m_stateMovement(nullptr)
{

}

Alien::~Alien()
{
    if (m_stateMovement != nullptr)
        delete m_stateMovement;
}

void Alien::setState(AiStates const& t_state, sf::Vector2f* t_arg)
{
    if (m_currentState != t_state)
    {
        m_currentState = t_state;
        if (m_stateMovement != nullptr)
        {
            m_stateMovement->onExit();
            delete m_stateMovement;
        }

        switch (m_currentState)
        {
        case AiStates::WANDER:
            m_stateMovement = new WanderState(&m_velocity);
            break;
        case AiStates::SEEK:
            m_stateMovement = new SeekState(&(*t_arg));
            break;
        case AiStates::ARRIVE:
            break;
        case AiStates::FLEE:
            break;
        }
        m_stateMovement->onEnter();
    }
}

void Alien::update(sf::Time t_dt)
{
    Entity::update(t_dt);
    m_stateMovement->update(t_dt);
}
