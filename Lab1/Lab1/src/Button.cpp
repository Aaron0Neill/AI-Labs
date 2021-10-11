#include "Button.h"

Button::Button(sf::Texture& t_tex, sf::Font& t_font, std::string t_name) : 
	m_caller(nullptr),
	m_arg(AiStates::NONE),
	m_func(nullptr)
{
	m_text.setFont(t_font);
	m_text.setString(t_name);

	m_sprite.setTexture(t_tex);
	m_sprite.setTextureRect(sf::IntRect(0,0,128,64));
}

//****************************************

void Button::setPosition(const sf::Vector2f& t_pos)
{
	sf::Vector2f half = { m_sprite.getGlobalBounds().width / 2, m_sprite.getGlobalBounds().height / 2};
	m_sprite.setPosition(t_pos - half);
	half = { m_text.getGlobalBounds().width / 2 , m_text.getGlobalBounds().height};
	m_text.setPosition(t_pos - half);
}

//****************************************

void Button::onHover()
{
	m_sprite.setTextureRect(sf::IntRect(128, 0, 128, 64));
}

//****************************************

void Button::onClick()
{
	m_sprite.setTextureRect(sf::IntRect(256, 0, 128, 64));
}

//****************************************

void Button::onRelease()
{
	m_sprite.setTextureRect(sf::IntRect(0, 0, 128, 64));
	if (m_func != nullptr)
		m_func->call();
}

//****************************************

void Button::offHover()
{
	m_sprite.setTextureRect(sf::IntRect(0, 0, 128, 64));
}

//****************************************

void Button::draw(sf::RenderTarget& t_target, sf::RenderStates s) const
{
	t_target.draw(m_sprite);
	t_target.draw(m_text);
}
