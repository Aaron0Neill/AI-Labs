#include "WanderState.h"

WanderState::WanderState(Alien* t_alien) : 
    State(t_alien),
    m_targetCtr(50),
    m_targetRadius(50),
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
    printf("Entering Wander State\n");
    if (m_alien != nullptr)
        m_alien->m_body.setColor(sf::Color::Cyan);

    if (m_alien->m_target == nullptr)
        m_alien->m_target = new sf::Vector2f();
    updateTarget();
}

//****************************************

void WanderState::update(sf::Time t_dt)
{
    m_waitTime -= t_dt.asSeconds();
    if (m_waitTime <= 0)
        updateTarget();

    moveToTarget(getUnitVec(*m_alien->m_target - m_alien->m_position), t_dt);
}

//****************************************

void WanderState::onExit()
{
    delete m_alien->m_target;
    if (m_alien != nullptr)
        m_alien->m_body.setColor(sf::Color(100,100,100,100));
    printf("Exiting Wander State\n");
}

//****************************************

void WanderState::updateTarget()
{
    sf::Vector2f wanderOffsetPt = m_alien->m_position + (getUnitVec(m_alien->m_velocity) * m_targetCtr);
    float randRad = Deg2Rad(static_cast<float>(rand() % 360));
    *m_alien->m_target = (sf::Vector2f{cosf(randRad), sinf(randRad)} * m_targetRadius) + wanderOffsetPt;
    m_waitTime = 1;
}