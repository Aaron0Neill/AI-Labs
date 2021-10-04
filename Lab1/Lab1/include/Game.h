#pragma once

#include <SFML/Graphics.hpp>
#include "Globals.h"
#include "NPC.h"
#include "Player.h"

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

	NPC m_npc;
	Player m_player;
	sf::RenderWindow m_window;
};