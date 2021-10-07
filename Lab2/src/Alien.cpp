#include "include/Alien.h"

Alien::Alien(std::string const& t_filename) :
	Entity(t_filename),
	m_currentState(AiStates::NONE),
	m_stateFunction(nullptr),
	m_changeTime(0),
	m_target(nullptr)
{
}

Alien::Alien(std::string const& t_filename, AiStates const& t_state) :
	Alien(t_filename)
{
	setState(t_state);
}

//***************************************

void Alien::update(sf::Time t_dt)
{
	Entity::update(t_dt);

	if (m_stateFunction != nullptr)
		m_stateFunction(this, t_dt);
}

//***************************************

void Alien::setState(AiStates const& t_state)
{
	m_currentState = t_state;

	switch (m_currentState)
	{
	case AiStates::WANDER:
		m_stateFunction = &Alien::kinematicWander;
		m_changeTime = rand() % 3;
		break;
	case AiStates::SEEK:
		m_stateFunction = &Alien::kinematicSeek;
		m_velocityScaler = 50;
		break;
	case AiStates::ARRIVE:
		m_stateFunction = &Alien::kinematicArrive;
		m_velocityScaler = 0;
		break;
	case AiStates::FLEE:
		m_stateFunction = &Alien::kinematicFlee;
		break;
	default:
		break;
	}
}

//***************************************

void Alien::setTarget(sf::Vector2f* t_target)
{
	m_target = t_target;
}

//***************************************

void Alien::setArriveDistance(float const& t_dist)
{
	m_arriveDistance = t_dist;
}

//***************************************

void Alien::kinematicWander(sf::Time t_dt)
{
	m_changeTime -= t_dt.asSeconds();

	if (m_changeTime < 0)
	{
		m_heading = rand() % 360;
		updateVelocity();
		m_changeTime = rand() % 3;
	}
}

//***************************************

void Alien::kinematicSeek(sf::Time t_dt)
{
	if (m_target != nullptr)
	{
		sf::Vector2f diffVec = *m_target - m_position;

		if (SquaredMagnitude(diffVec) < m_arriveDistance * m_arriveDistance)
		{
			setState(AiStates::ARRIVE);
		}

		float deltaHeading = atan2f(diffVec.y, diffVec.x);

		if (m_heading != deltaHeading)
		{
			m_heading = deltaHeading;
			updateVelocity();
		}
	}
	else
	{
		printf("Trying to seek with no target\n");
		printf("Switching to wander\n");
		setState(AiStates::WANDER);
	}
}

//***************************************

void Alien::kinematicArrive(sf::Time t_dt)
{
	if (m_target != nullptr)
	{
		sf::Vector2f diffVec = *m_target - m_position;

		if (SquaredMagnitude(diffVec) > m_arriveDistance * m_arriveDistance)
		{
			setState(AiStates::SEEK);
		}

		float deltaHeading = atan2f(diffVec.y, diffVec.x);
		if (m_heading != deltaHeading)
		{
			m_heading = deltaHeading;
			updateVelocity();
		}
	}
	else
	{
		printf("Trying to seek with no target\n");
		printf("Switching to wander\n");
		setState(AiStates::WANDER);
	}
}

//***************************************

void Alien::kinematicFlee(sf::Time t_dt)
{
	if (m_target != nullptr)
	{
		sf::Vector2f diffVec = m_position - *m_target;

		float deltaHeading = atan2f(diffVec.y, diffVec.x);

		if (m_heading != deltaHeading)
		{
			m_heading = deltaHeading;
			updateVelocity();
		}
	}
	else
	{
		printf("Trying to seek with no target\n");
		printf("Switching to wander\n");
		setState(AiStates::WANDER);
	}
}
