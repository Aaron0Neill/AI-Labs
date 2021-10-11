#include "Entity.h"

Entity::Entity(const std::string& t_filename, const std::string& t_name) :
	m_velocityScaler(50),
	m_name(t_name)
{
	m_position = sf::Vector2f(static_cast<float>(SCREEN_WIDTH / 2), static_cast<float>(SCREEN_HEIGHT / 2));
	m_body.setPosition(m_position);
	m_tex.loadFromFile("assets/" + t_filename);
	m_body.setTexture(m_tex);
	m_body.setOrigin(m_body.getGlobalBounds().width / 2.f,m_body.getGlobalBounds().height / 2.f);
	updateRotation();
}

//****************************************

void Entity::update(sf::Time t_dt)
{
	m_position += m_velocity * t_dt.asSeconds();

	wrapCheck();
	m_body.setPosition(m_position);
}

//****************************************

void Entity::wrapCheck()
{
	if (static_cast<unsigned>(m_position.x) > SCREEN_WIDTH - DEBUG_WIDTH)
		m_position = { static_cast<float>(m_position.x > SCREEN_WIDTH - DEBUG_WIDTH ? 0 : SCREEN_WIDTH - DEBUG_WIDTH), m_position.y };

	if (static_cast<unsigned>(m_position.y) > SCREEN_HEIGHT)
		m_position = { m_position.x, static_cast<float>(m_position.y > SCREEN_HEIGHT ? 0 : SCREEN_HEIGHT) };
}

//****************************************

void Entity::updateRotation()
{
	m_body.setRotation(Rad2Deg(atan2f(m_velocity.y, m_velocity.x)));
}

//****************************************

void Entity::draw(sf::RenderTarget& t_target, sf::RenderStates t_state)const
{
	t_target.draw(m_body);
}
