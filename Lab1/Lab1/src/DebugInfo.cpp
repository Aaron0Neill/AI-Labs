#include "DebugInfo.h"
#include <cstdio>

DebugInfo::DebugInfo(sf::Font& t_font, std::function<void(Game*)> t_func, Game* t_game) :
	m_show(true)
{
	m_buttonTex.loadFromFile("assets/Button.png");

	m_objectName.setFont(t_font);
	m_objectState.setFont(t_font);
	m_objectName.setCharacterSize(36);
	m_objectState.setCharacterSize(28);

	m_buttons.push_back(new Button(m_buttonTex, t_font, "Arrive"));
	m_buttons.push_back(new Button(m_buttonTex, t_font, "Pursue"));
	m_buttons.push_back(new Button(m_buttonTex, t_font, "Seek"));
	m_buttons.push_back(new Button(m_buttonTex, t_font, "Wander"));
	m_buttons.push_back(new Button(m_buttonTex, t_font, "Disable Alien"));
	m_buttons.push_back(new Button(m_buttonTex, t_font, "Create Alien"));

	m_buttons.at(0)->addFunction(&Alien::setState, &m_alien, AiStates::ARRIVE);
	m_buttons.at(1)->addFunction(&Alien::setState, &m_alien, AiStates::PURSUE);
	m_buttons.at(2)->addFunction(&Alien::setState, &m_alien, AiStates::SEEK);
	m_buttons.at(3)->addFunction(&Alien::setState, &m_alien, AiStates::WANDER);
	m_buttons.at(4)->addFunction(&Alien::setState, &m_alien, AiStates::NONE);
	m_buttons.at(5)->addFunction(t_func, t_game);

	m_currentButton = m_buttons.at(0);
	m_currentButton->onHover();
}

//****************************************

DebugInfo::~DebugInfo()
{
}

//****************************************

void DebugInfo::setAlien(Alien* t_alien)
{
	m_alien = t_alien;
}

//****************************************

void DebugInfo::init()
{
	sf::Vector2f startPos = { static_cast<float>(SCREEN_WIDTH - (DEBUG_WIDTH / 2)), 200.0f };

	for (auto& btn : m_buttons)
	{
		btn->setPosition(startPos);
		startPos.y += 100;
	}
}

//****************************************

void DebugInfo::showAlien(Alien* t_alien)
{
	m_alien = t_alien;

	m_objectName.setString("Name: " + m_alien->getName());
	m_objectName.setPosition({ static_cast<float>((SCREEN_WIDTH - (DEBUG_WIDTH / 2)) - m_objectName.getGlobalBounds().width / 2) , 50 });

	m_objectState.setString("State: " + m_alien->getState());
	m_objectState.setPosition({ static_cast<float>(SCREEN_WIDTH - (DEBUG_WIDTH / 2) - m_objectState.getGlobalBounds().width / 2), 100 });

	m_show = true;
}

//****************************************

void DebugInfo::updateButton(sf::Vector2f t_pos)
{
	for(auto& btn : m_buttons)
		if (btn->contains(t_pos))
			if (btn != m_currentButton)
			{
				m_currentButton->offHover();
				m_currentButton = btn;
				m_currentButton->onHover();
			}
}

//****************************************

void DebugInfo::clickButton(sf::Vector2f t_pos)
{
	if (m_currentButton->contains(t_pos))
		m_currentButton->onClick();
}

//****************************************

void DebugInfo::releaseButton(sf::Vector2f t_pos)
{
	if (m_currentButton->contains(t_pos))
	{
		m_currentButton->onRelease();
		showAlien(m_alien);
	}
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

		for (auto& btn : m_buttons)
		{
			t_target.draw(*btn);
		}
	}
}
