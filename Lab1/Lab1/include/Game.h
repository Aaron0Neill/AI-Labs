#pragma once

#include <SFML/Graphics.hpp>
#include "Globals.h"
#include "NPC.h"
#include "Player.h"

/// <summary>
/// Main Game Loop for the project.
/// Handles inputs from the user, updates all the necessary classes and then renders them to the screen at 60fps
/// </summary>
class Game
{
public: 
	/// <summary>
	/// Default Constructor
	/// Initializes NPC and Player
	/// </summary>
	Game();

	
	~Game()= default;

	/// <summary>
	/// Function to start the game loop and keep it running at 60fps
	/// </summary>
	void run();
private:

	/// <summary>
	/// Handles all events that surround the window
	/// </summary>
	void handleInput();

	/// <summary>
	/// Updates all objects that need to be updated 60 times/second
	/// </summary>
	/// <param name="t_deltaTime"> time between frames </param>
	void update(sf::Time t_deltaTime);

	/// <summary>
	/// Draws all relative objects to the screen for the user to see
	/// </summary>
	void render();

	NPC m_npc;
	Player m_player;
	sf::RenderWindow m_window;
};