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
	~Game()= default;
	void run();
private:

	void handleInput();
	void update(sf::Time t_deltaTime);
	void render();

	Player m_player;
	Alien m_wanderAlien;
	Alien m_seekAlien;

	sf::Font m_gameFont;

	DebugInfo m_info;

	std::vector<Entity*> m_entities;
	sf::VertexArray m_debugArea;
	sf::RenderWindow m_window;
};
#endif