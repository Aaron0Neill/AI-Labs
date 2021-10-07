#pragma once

#include "Entity.h"
#include <functional>
#include "MathUtils.h"

enum class AiStates
{
	NONE = -1,
	WANDER,
	SEEK,
	ARRIVE,
	FLEE
};

class Alien : public Entity
{
public:
	Alien(std::string const& t_filename);
	Alien(std::string const& t_filename, AiStates const& t_state);
	~Alien() = default;

	virtual void update(sf::Time t_dt) override;

	virtual void setState(AiStates const& t_state);

	virtual void setTarget(sf::Vector2f* t_target);

	virtual void setArriveDistance(float const& t_dist);
private:

	void kinematicWander(sf::Time t_dt);
	void kinematicSeek(sf::Time t_dt);
	void kinematicArrive(sf::Time t_dt);
	void kinematicFlee(sf::Time t_dt);

	AiStates m_currentState;
	std::function<void(Alien*, sf::Time)> m_stateFunction;

	float m_changeTime;
	float m_arriveDistance;
	sf::Vector2f* m_target;
};