#include "..\include\Player.h"

Player::Player(std::string const& t_name) :
	Entity("Player.png", t_name),
	m_playerIncreaseSpeed(10),
	m_playerRotationSpeed(Deg2Rad(45)),
	m_heading(0),
	m_maxSpeed(75),
	m_minSpeed(25)
{
}

//****************************************

Player::~Player()
{
}

//****************************************

void Player::increaseSpeed()
{
	m_velocityScaler += m_playerIncreaseSpeed;
	if (m_velocityScaler > m_maxSpeed)
		m_velocityScaler = m_maxSpeed;
}

//****************************************

void Player::decreaseSpeed()
{
	m_velocityScaler -= m_playerIncreaseSpeed;
	if (m_velocityScaler < m_minSpeed)
		m_velocityScaler = m_minSpeed;
}

//****************************************

void Player::turnRight(float t_dt)
{
	m_heading += m_playerRotationSpeed * t_dt;
	m_velocity = {cosf(m_heading), sinf(m_heading) };
	updateRotation();
}

//****************************************

void Player::turnLeft(float t_dt)
{
	m_heading -= m_playerRotationSpeed * t_dt;
	m_velocity = { cosf(m_heading), sinf(m_heading) };
	updateRotation();
}

//****************************************

sf::Vector2f& Player::getPosition()
{
	return m_position;
}