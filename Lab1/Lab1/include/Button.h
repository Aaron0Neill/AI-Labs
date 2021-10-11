#ifndef BUTTON_INCLUDE
#define BUTTON_INCLUDE

#include <SFML/Graphics.hpp>
#include <string>
#include <functional>
#include "Alien.h"
#include "ButtonFunction.h"

class Game;

class Button : public sf::Drawable
{
public:
	Button(sf::Texture& t_tex, sf::Font& t_font, std::string t_name);

	void setPosition(const sf::Vector2f& t_pos);

	void onHover();

	void onClick();

	void onRelease();

	void offHover();

	void draw(sf::RenderTarget& t_target, sf::RenderStates s = sf::RenderStates::Default)const override;

	inline bool contains(sf::Vector2f t_pos)
	{
		return m_sprite.getGlobalBounds().contains(t_pos);
	}

	inline void addFunction(std::function<void(Alien*, const AiStates&)> t_func, Alien** t_caller, AiStates t_arg)
	{
		m_func = new ArgsFunction<Alien, AiStates>(t_func, t_caller, t_arg);
	}

	inline void addFunction(std::function<void(Game*)> t_func, Game* t_caller)
	{
		m_func = new ClassFunction<Game>(t_func, t_caller);
	}
private:
	sf::Sprite m_sprite;
	sf::Text m_text;
	ButtonFunction* m_func;
	Alien* m_caller;
	AiStates m_arg;
};
#endif