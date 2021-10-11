#ifndef GAME_INCLUDE
#define GAME_INCLUDE

#include <SFML/Graphics.hpp>
#include "Globals.h"
#include "NPC.h"
#include "Player.h"
#include "Alien.h"
#include <vector>
#include "DebugInfo.h"

class Game
{
public: 
	Game();
	~Game();
	void run();
private:

	void handleInput();
	void update(sf::Time t_deltaTime);
	void render();

	void addAlien();

	Player m_player;
	Alien m_GLaDOS;
	Alien m_clapTrap;

	sf::Font m_gameFont;

	DebugInfo m_info;

	std::vector<Alien*> m_aliens;
	sf::VertexArray m_debugArea;
	sf::RenderWindow m_window;
};
#endif