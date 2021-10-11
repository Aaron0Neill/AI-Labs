#ifndef DEBUG_INFO_INCLUDE
#define DEBUG_INFO_INCLUDE

#include <SFML/Graphics.hpp>
#include "Button.h"
#include <vector>

class DebugInfo : public sf::Drawable
{
public:
	DebugInfo(sf::Font& t_font, std::function<void(Game*)> t_func, Game* t_game);
	~DebugInfo();

	void setAlien(Alien* t_alien);

	void init();

	void showAlien(Alien* m_alien);

	void updateButton(sf::Vector2f);

	void clickButton(sf::Vector2f);

	void releaseButton(sf::Vector2f);

	void hide();

	void draw(sf::RenderTarget& t_target, sf::RenderStates s = sf::RenderStates::Default)const override;
private:
	Alien* m_alien;
	sf::Text m_objectName;
	sf::Text m_objectState;

	sf::Texture m_buttonTex;

	Button* m_currentButton;

	std::vector<Button*> m_buttons;

	bool m_show;
};

#endif