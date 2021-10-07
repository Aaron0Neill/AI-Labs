#pragma once

#include <cmath>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "Globals.h"

/// <summary>
/// Base Class for the behavior of the Player and NPC
/// </summary>
class Entity : public sf::Drawable
{
public:
	/// <summary>
	/// Basic Constructor for the Entity
	/// Takes the name of the texture file as an argument
	/// </summary>
	/// <param name="t_filename">Name of the texture file</param>
	Entity(std::string const& t_filename);
	~Entity() = default;

	/// <summary>
	/// Virutal update function so Inherited classes can use it
	/// </summary>
	/// <param name="t_dt">delta time</param>
	virtual void update(sf::Time t_dt);

	/// <summary>
	/// Function to check if the entity has gone off the screen and 
	/// fix its position if it has
	/// </summary>
	void wrapCheck();

	void updateRotation();

	void updateVelocity();

	/// <summary>
	/// Inherited class to draw textures to a target
	/// </summary>
	/// <param name="t_target">target to draw the texture</param>
	/// <param name="t_state">different ways to draw it</param>
	virtual void draw(sf::RenderTarget& t_target, sf::RenderStates t_state = sf::RenderStates::Default)const override;

	virtual sf::Sprite& getSprite() { return m_body; }

	virtual void setPosition(sf::Vector2f const& t_pos);
protected:
	float m_heading; // what direction the class is facing (0-360)
	sf::Vector2f m_velocity; // vector its moving by
	sf::Vector2f m_position; // where it is
	float m_velocityScaler; // scalar to the velocity 
	sf::Sprite m_body;
	sf::Texture m_tex;
};