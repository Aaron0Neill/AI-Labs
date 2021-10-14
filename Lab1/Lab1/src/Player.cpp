#include "..\include\Player.h"

Player::Player(std::string const& t_name) :
	Entity("Player.png", t_name),
	m_playerIncreaseSpeed(10),
	m_playerRotationSpeed(Deg2Rad(45)),
	m_heading(0),
	m_maxSpeed(150),
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
	m_velocity = getUnitVec(m_velocity) * m_velocityScaler;
}

//****************************************

void Player::decreaseSpeed()
{
	m_velocityScaler -= m_playerIncreaseSpeed;
	if (m_velocityScaler < m_minSpeed)
		m_velocityScaler = m_minSpeed;
	m_velocity = getUnitVec(m_velocity) * m_velocityScaler;
}

//****************************************

void Player::turnRight(float t_dt)
{
	m_heading += m_playerRotationSpeed * t_dt;
	m_velocity = sf::Vector2f{cosf(m_heading), sinf(m_heading) } * m_velocityScaler;
	updateRotation();
}

//****************************************

void Player::turnLeft(float t_dt)
{
	m_heading -= m_playerRotationSpeed * t_dt;
	m_velocity = sf::Vector2f{ cosf(m_heading), sinf(m_heading) } *m_velocityScaler;
	updateRotation();
}

//****************************************

sf::Vector2f& Player::getPosition()
{
	return m_position;
}

//****************************************

sf::Vector2f& Player::getVelocity()
{
	return m_velocity;
}
