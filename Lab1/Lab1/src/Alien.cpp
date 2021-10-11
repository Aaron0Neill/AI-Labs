#include "include/Alien.h"

Alien::Alien(std::string const& t_name) :
    Entity("Alien.png", t_name),
    m_currentState(AiStates::NONE),
    m_stateMovement(nullptr),
    m_target(nullptr)
{
    m_mapping.emplace(AiStates::NONE, "None");
    m_mapping.emplace(AiStates::WANDER, "Wander");
    m_mapping.emplace(AiStates::SEEK, "Seek");
    m_mapping.emplace(AiStates::ARRIVE, "Arrive");
    m_mapping.emplace(AiStates::PURSUE, "Pursue");
}

//****************************************

Alien::~Alien()
{
    if (m_stateMovement != nullptr)
        delete m_stateMovement;
}

//****************************************

void Alien::setState(AiStates const& t_state)
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
            m_target = nullptr;
            m_stateMovement = new WanderState(this);
            break;
        case AiStates::SEEK:
            m_stateMovement = new SeekState(this);
            break;
        case AiStates::ARRIVE:
            m_stateMovement = new ArriveState(this);
            break;
        case AiStates::FLEE:
            break;
        }
        m_stateMovement->onEnter();
    }
}

//****************************************

void Alien::update(sf::Time t_dt)
{
    m_stateMovement->update(t_dt); // update velocity
    updateRotation(); // update rotation
    m_position += m_velocity; // make movement

    wrapCheck();
    m_body.setPosition(m_position);
}

//****************************************

void Alien::setTarget(sf::Vector2f* t_target)
{
    m_target = t_target;
}

//****************************************

void Alien::setPosition(sf::Vector2f t_pos)
{
    m_position = t_pos;
    m_body.setPosition(m_position);
}

//***************************************

const std::string& Alien::getState()
{
    return m_mapping.at(m_currentState);
}
