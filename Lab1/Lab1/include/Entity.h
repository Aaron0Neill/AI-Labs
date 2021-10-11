#ifndef ENTITY_INCLUDE
#define ENTITY_INCLUDE

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "Globals.h"
#include <cmath>
#include "MathUtils.h"

/// <summary>
/// Entity class 
/// </summary>
class Entity : public sf::Drawable
{
public:
	/// <summary>
	/// Basic Constructor for the Entity
	/// Takes the name of the texture file as an argument
	/// </summary>
	/// <param name="t_filename">Name of the texture file</param>
	Entity(const std::string& t_filename, const std::string& t_name);
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

	/// <summary>
	/// Rotates the entity to face in the direction of the velocity
	/// </summary>
	void updateRotation();

	/// <summary>
	/// Inherited class to draw textures to a target
	/// </summary>
	/// <param name="t_target">target to draw the texture</param>
	/// <param name="t_state">different ways to draw it</param>
	virtual void draw(sf::RenderTarget& t_target, sf::RenderStates t_state = sf::RenderStates::Default)const override;


	const std::string& getName() { return m_name; }
protected:

	std::string m_name;
	friend class State;
	sf::Vector2f m_velocity;
	sf::Vector2f m_position;
	float m_velocityScaler;
	sf::Sprite m_body;
	sf::Texture m_tex;
};
#endif