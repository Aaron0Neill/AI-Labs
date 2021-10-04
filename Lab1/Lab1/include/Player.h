#pragma once

#include "Entity.h"

/// <summary>
/// Player controlled implemenetation of Entity
/// </summary>
class Player : public Entity
{
public:
	/// <summary>
	/// Creates the player and assigns it the texture that matches the filename
	/// </summary>
	/// <param name="t_filename"> name of the texture file </param>
	Player(std::string const& t_filename);
	~Player();

	/// <summary>
	/// Increase the speed the player is moving at
	/// </summary>
	void increaseSpeed();

	/// <summary>
	/// Decrease the speed the player is moving at
	/// </summary>
	void decreaseSpeed();

	/// <summary>
	/// Change the heading and allow the player to turn right
	/// </summary>
	/// <param name="t_dt"> Time per frame so the player turns at a smooth amount </param> 
	void turnRight(float t_dt);

	/// <summary>
	/// Change the heading and allow the player to turn left 
	/// </summary>
	/// <param name="t_dt">Time per frame so the player turns at a smooth amount</param>
	void turnLeft(float t_dt);

private:
	int m_playerIncreaseSpeed; // how much the player increases speed 
	float m_playerRotationSpeed; // how much the player rotates by
};