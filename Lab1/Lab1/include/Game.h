#ifndef GAME_INCLUDE
#define GAME_INCLUDE

#include <SFML/Graphics.hpp>
#include "Globals.h"
#include "NPC.h"
#include "Player.h"
#include "Alien.h"
#include <vector>

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

	std::vector<Entity*> m_entities;

	sf::RenderWindow m_window;
};
#endif