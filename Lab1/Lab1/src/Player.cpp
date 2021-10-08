#include "..\include\Player.h"

Player::Player(std::string const& t_name) :
	Entity("Player.png", t_name),
	m_playerIncreaseSpeed(10),
	m_playerRotationSpeed(Deg2Rad(45))
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
}

//****************************************

void Player::decreaseSpeed()
{
	m_velocityScaler -= m_playerIncreaseSpeed;
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