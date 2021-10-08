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
            m_stateMovement = new WanderState(this);
            std::cout << "My Heading: " << m_heading << std::endl;
            break;
        case AiStates::SEEK:
            m_stateMovement = new SeekState(this);
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
    m_stateMovement->update(t_dt);
    m_position += m_velocity * m_velocityScaler * t_dt.asSeconds();
    wrapCheck();
    updateRotation();
    m_body.setPosition(m_position);
}

void Alien::setTarget(sf::Vector2f* t_target)
{
    m_target = t_target;
}
