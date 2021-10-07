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

void Player::turnRight(float t_dt)
{
	m_heading += m_playerRotationSpeed * t_dt;
	m_velocity = { static_cast<float>(cos(m_heading)), static_cast<float>(sin(m_heading)) };
	updateRotation();
}

void Player::turnLeft(float t_dt)
{
	m_heading -= m_playerRotationSpeed * t_dt;
	m_velocity = { static_cast<float>(cos(m_heading)), static_cast<float>(sin(m_heading)) };
	updateRotation();
}

sf::Vector2f& Player::getPosition()
{
	return m_position;
}