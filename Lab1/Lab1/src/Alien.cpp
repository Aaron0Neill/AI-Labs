#include "include/Alien.h"

Alien::Alien(std::string const& t_name) :
    Entity("Alien.png", t_name),
    m_currentState(AiStates::NONE),
    m_stateMovement(nullptr),
    m_target(nullptr),
    m_visionCone(sf::TriangleFan),
    m_visionDistance(150.0f),
    m_visionArc(Deg2Rad(45)),
    m_baseColor(255,255,255,150),
    m_endColor(255,255,255,50)
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
        if (m_currentState == AiStates::NONE)
        {
            m_stateMovement->onExit();
            delete m_stateMovement;
        }

        switch (m_currentState)
        {
        case AiStates::NONE:
            m_stateMovement = nullptr;
            break;
        case AiStates::WANDER:
            m_stateMovement = new WanderState(this);
            break;
        case AiStates::SEEK:
            m_stateMovement = new SeekState(this);
            break;
        case AiStates::ARRIVE:
            m_stateMovement = new ArriveState(this);
            break;
        case AiStates::PURSUE:
            m_stateMovement = new PursueState(this);
            break;
        }

        if (m_stateMovement != nullptr)
            m_stateMovement->onEnter();

    }
}

//****************************************

void Alien::update(sf::Time t_dt)
{
    if (m_stateMovement != nullptr)
    {
        m_stateMovement->update(t_dt); // update velocity

        updateRotation(); // update rotation
        m_position += m_velocity; // make movement

        wrapCheck();
        m_body.setPosition(m_position);

        float heading = getHeading();
        m_visionCone.clear();
        m_visionCone.append(sf::Vertex{ m_position, m_baseColor });
        updateVisionCone(heading - m_visionArc, heading + m_visionArc);
    }
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

void Alien::setPlayerVelocity(sf::Vector2f* t_playerVelo)
{
    m_playerVelo = t_playerVelo;
}

//***************************************

std::string Alien::getState()
{
    if (m_stateMovement != nullptr)
        return m_stateMovement->getName();
    std::string r = "Disabled";
    return r;
}

//***************************************

void Alien::draw(sf::RenderTarget& t_target, sf::RenderStates s) const
{
    t_target.draw(m_body);
    t_target.draw(m_visionCone);
}

//***************************************

void Alien::updateVisionCone(float t_min, float t_max)
{
    for (float a = t_min; a < t_max; a += Deg2Rad(5))
    {
        m_visionCone.append(sf::Vertex{ sf::Vector2f(cosf(a) * m_visionDistance, sinf(a) * m_visionDistance) + m_position, m_endColor });
    }

    float minCross = CrossProduct(sf::Vector2f(cosf(t_min), sinf(t_min)), *m_target - m_position);
    float maxCross = CrossProduct(sf::Vector2f(cosf(t_max), sinf(t_max)), *m_target - m_position);

    if (minCross > 0 && maxCross < 0)
    {
        if (VectorSquaredDistance(*m_target - m_position) < m_visionDistance * m_visionDistance)
        {
            m_baseColor = sf::Color(255, 0, 0, 150);
            m_endColor = sf::Color(255, 0, 0, 50);
        }
        else
        {
            m_baseColor = sf::Color(255, 255, 255, 150);
            m_endColor = sf::Color(255, 255, 255, 50);
        }
    }
    else
    {
        m_baseColor = sf::Color(255, 255,255, 150);
        m_endColor =  sf::Color(255, 255,255, 50);
    }
}