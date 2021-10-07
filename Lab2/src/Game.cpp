#include "include/Game.h"

Game::Game() :
	m_window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "AI Lab1"),
	m_npc("NPC.png"),
	m_player("Player.png"),
	m_wander("Alien.png"),
	m_seekAlien("Alien.png"),
	m_fleeAlien("Alien.png")
{
	m_entities.push_back(&m_npc);
	m_entities.push_back(&m_wander);
	m_entities.push_back(&m_player);
	m_entities.push_back(&m_seekAlien);
	m_entities.push_back(&m_fleeAlien);

	m_seekAlien.getSprite().setColor(sf::Color::Red);
	m_seekAlien.setPosition({50,50});

	m_fleeAlien.getSprite().setColor(sf::Color::Green);
	m_fleeAlien.setPosition({ 500,500 });
	m_fleeAlien.setState(AiStates::FLEE);
	m_fleeAlien.setTarget(&m_player.getPosition());

	m_seekAlien.setState(AiStates::SEEK);
	m_seekAlien.setTarget(&m_player.getPosition());
	m_wander.setState(AiStates::WANDER);
}

//****************************************

void Game::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	const float fps{ 60.0f };
	sf::Time timePerFrame = sf::seconds(1.0f / fps);
	while (m_window.isOpen())
	{
		handleInput();
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > timePerFrame)
		{
			timeSinceLastUpdate -= timePerFrame;
			handleInput();
			update(timePerFrame);
		}
		render();
	}
}

//****************************************

void Game::handleInput()
{
	sf::Event currentEvent;
	while (m_window.pollEvent(currentEvent))
	{
		if (sf::Event::Closed == currentEvent.type)
		{
			m_window.close();
		}
		if (sf::Event::KeyPressed == currentEvent.type)
		{
		}
	}
}

//****************************************

void Game::update(sf::Time t_deltaTime)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		m_player.turnLeft(t_deltaTime.asSeconds());
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		m_player.turnRight(t_deltaTime.asSeconds());

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		m_player.decreaseSpeed();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		m_player.increaseSpeed();
	
	for (auto& e : m_entities)
		e->update(t_deltaTime);
}

//****************************************

void Game::render()
{
	m_window.clear();
	
	for (auto& e : m_entities)
		m_window.draw(*e);

	m_window.display();
}
