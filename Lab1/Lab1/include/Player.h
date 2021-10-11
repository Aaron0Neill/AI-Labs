#pragma once

#include "Entity.h"

/// <summary>
/// Player controlled implemenetation of Entity
/// </summary>
class Player : public Entity
{
public:
	Player(std::string const& t_name);
	~Player();

	void increaseSpeed();

	void decreaseSpeed();

	void turnRight(float t_dt);

	void turnLeft(float t_dt);

	sf::Vector2f& getPosition();

private:
	int m_playerIncreaseSpeed;
	float m_playerRotationSpeed;
	float m_heading;

	int m_maxSpeed;
	int m_minSpeed;
};