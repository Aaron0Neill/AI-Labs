#include "Entity.h"

Entity::Entity(std::string const& t_filename) : 
	m_velocityScaler(50)
{
	m_position = sf::Vector2f(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
	m_body.setPosition(m_position);
	m_tex.loadFromFile("assets/" + t_filename);
	m_body.setTexture(m_tex);
	m_body.setOrigin(m_body.getGlobalBounds().width / 2.f,m_body.getGlobalBounds().height / 2.f);
	m_heading = (rand() % 360) * (PI / 180.0);
	m_velocity = { static_cast<float>(cos(m_heading)), static_cast<float>(sin(m_heading))};
	updateRotation();
}

//****************************************

void Entity::update(sf::Time t_dt)
{
	m_position += m_velocity * m_velocityScaler * t_dt.asSeconds();

	wrapCheck();
	m_body.setPosition(m_position);
}

//****************************************

void Entity::wrapCheck()
{
	if (static_cast<unsigned>(m_position.x) > SCREEN_WIDTH)
		m_position = { static_cast<float>(m_position.x > SCREEN_WIDTH ? 0 : SCREEN_WIDTH), m_position.y };

	if (static_cast<unsigned>(m_position.y) > SCREEN_HEIGHT)
		m_position = { m_position.x, static_cast<float>(m_position.y > SCREEN_HEIGHT ? 0 : SCREEN_HEIGHT) };
}

//****************************************

void Entity::updateRotation()
{
	m_body.setRotation(m_heading * 180.0 / PI);
}

//****************************************

void Entity::draw(sf::RenderTarget& t_target, sf::RenderStates t_state)const
{
	t_target.draw(m_body);
}
