#ifndef BUTTON_INCLUDE
#define BUTTON_INCLUDE

#include <SFML/Graphics.hpp>
#include <string>
#include <functional>
#include "Alien.h"

class Button : sf::Drawable
{
public:
	Button(sf::Texture& t_tex, sf::Font& t_font, std::string t_name);

	void setPosition(const sf::Vector2f& t_pos);

	void onHover();

	void onClick();

	void onRelease();

	void draw(sf::RenderTarget& t_target, sf::RenderStates s = sf::RenderStates::Default)const override;

	inline void addFunction(std::function<void(Alien*, const AiStates&)> t_func, Alien* t_caller, AiStates t_arg)
	{
		m_func = t_func;
		m_caller = t_caller;
		m_arg = t_arg;
	}
private:
	sf::Sprite m_sprite;
	sf::Text m_text;
	std::function<void(Alien*, const AiStates& t_state)> m_func;
	Alien* m_caller;
	AiStates m_arg;
};
#endif