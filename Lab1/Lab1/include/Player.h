#pragma once

#include "Entity.h"

/// <summary>
/// Player controlled implemenetation of Entity
/// </summary>
class Player : public Entity
{
public:
	Player(std::string const& t_filename);
	~Player();

	void increaseSpeed();

	void decreaseSpeed();

	void turnRight(float t_dt);

	void turnLeft(float t_dt);

private:
	int m_playerIncreaseSpeed;
	float m_playerRotationSpeed;
};