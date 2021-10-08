#include "DebugInfo.h"
#include <cstdio>

DebugInfo::DebugInfo(sf::Font& t_font) :
	m_button(m_buttonTex, t_font, "Seek"),
	m_show(true)
{
	m_buttonTex.loadFromFile("assets/Button.png");

	m_objectName.setFont(t_font);
	m_objectState.setFont(t_font);
	m_objectName.setCharacterSize(36);
	m_objectState.setCharacterSize(28);
}

//****************************************

void DebugInfo::showAlien(Alien* t_alien)
{
	m_alien = t_alien;
	m_button.setPosition(sf::Vector2f{ static_cast<float>(SCREEN_WIDTH - (DEBUG_WIDTH / 2)), 200.0f });

	m_objectName.setString("Name: " + m_alien->getName());
	m_objectName.setPosition({ static_cast<float>((SCREEN_WIDTH - (DEBUG_WIDTH / 2)) - m_objectName.getGlobalBounds().width / 2) , 50 });

	m_objectState.setString("State: " + m_alien->getState());
	m_objectState.setPosition({ static_cast<float>(SCREEN_WIDTH - (DEBUG_WIDTH / 2) - m_objectState.getGlobalBounds().width / 2), 100 });

	m_button.addFunction(&Alien::setState, m_alien, AiStates::WANDER);
	m_show = true;
}

//****************************************

void DebugInfo::activateButton()
{
	m_button.onClick();
	showAlien(m_alien);
}

//****************************************

void DebugInfo::hide()
{
	m_show = false;
}

//****************************************

void DebugInfo::draw(sf::RenderTarget& t_target, sf::RenderStates s) const
{
	if (m_show)
	{
		t_target.draw(m_objectName);
		t_target.draw(m_objectState);

		m_button.draw(t_target);
	}
}
