#include "..\include\ArriveState.h"

ArriveState::ArriveState(Alien* t_alien) : 
	State(t_alien),
    m_offset(200)
{
}

//****************************************

ArriveState::~ArriveState()
{
}

//****************************************

void ArriveState::onEnter()
{
	printf("Entering Arrive State\n");

    if (m_alien != nullptr)
        m_alien->m_body.setColor(sf::Color::Magenta);

    if (m_alien->m_target == nullptr)
        printf("Error with seek state! Error: No target found\n");
}

//****************************************

void ArriveState::update(sf::Time t_dt)
{
    sf::Vector2f headingVec = *m_alien->m_target - m_alien->m_position;
    float headingDist = VectorSquaredDistance(headingVec);
    UnitVec(headingVec);
    headingVec *= headingDist - (m_offset * m_offset);

    moveToTarget(getUnitVec(headingVec), t_dt);
}

//****************************************

void ArriveState::onExit()
{
    if (m_alien != nullptr)
        m_alien->m_body.setColor(sf::Color(100,100,100,100));
	printf("Exiting Arrive State\n");
}
