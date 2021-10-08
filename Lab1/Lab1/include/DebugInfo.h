#ifndef DEBUG_INFO_INCLUDE
#define DEBUG_INFO_INCLUDE

#include <SFML/Graphics.hpp>
#include "Button.h"

class DebugInfo : public sf::Drawable
{
public:
	DebugInfo(sf::Font& t_font);

	void showAlien(Alien* m_alien);

	void activateButton();

	void hide();

	void draw(sf::RenderTarget& t_target, sf::RenderStates s = sf::RenderStates::Default)const override;
private:
	Alien* m_alien;
	sf::Text m_objectName;
	sf::Text m_objectState;

	sf::Texture m_buttonTex;

	Button m_button;

	bool m_show;
};

#endif