#include "..\include\Player.h"

Player::Player(std::string const& t_filename) :
	Entity(t_filename),
	m_playerIncreaseSpeed(10),
	m_playerRotationSpeed(45 * PI / 180.0)
{
}

Player::~Player()
{
}

void Player::increaseSpeed()
{
	m_velocityScaler += m_playerIncreaseSpeed;
}

void Player::decreaseSpeed()
{
	m_velocityScaler -= m_playerIncreaseSpeed;
}

//void Player::rotate(float t_dt)
//{
//	m_heading += m_playerRotationSpeed * t_dt;
//	m_velocity = { cos(m_heading), sin(m_heading) };
//	updateRotation();
//}