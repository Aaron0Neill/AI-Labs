#include "Game.h"

Game::Game() :
	m_window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "AI Lab1"),
	m_player("Ronald mcDonald"),
	m_wanderAlien("GLaDOS"),
	m_seekAlien("Seeker"),
	m_debugArea(sf::Quads),
	m_info(m_gameFont)
{
	m_gameFont.loadFromFile("assets/calibri.ttf");

	m_wanderAlien.setPosition({ 300,300 });

	m_wanderAlien.setState(AiStates::WANDER);
	m_wanderAlien.setTarget(&m_player.getPosition());

	m_seekAlien.setTarget(&m_player.getPosition());
	m_seekAlien.setState(AiStates::SEEK);
	m_seekAlien.setPosition({ 100,100 });

	m_entities.push_back(&m_player);
	m_entities.push_back(&m_wanderAlien);
	m_entities.push_back(&m_seekAlien);

	sf::Color inner = sf::Color(100, 100, 100, 100);
	sf::Color outer = sf::Color(100, 100, 100, 255);

	m_debugArea.append(sf::Vertex{ sf::Vector2f(static_cast<float>(SCREEN_WIDTH - DEBUG_WIDTH), 0.0f), inner });
	m_debugArea.append(sf::Vertex{ sf::Vector2f(static_cast<float>(SCREEN_WIDTH), 0.0f), outer });
	m_debugArea.append(sf::Vertex{ sf::Vector2f(static_cast<float>(SCREEN_WIDTH), static_cast<float>(SCREEN_HEIGHT)), outer });
	m_debugArea.append(sf::Vertex{ sf::Vector2f(static_cast<float>(SCREEN_WIDTH - DEBUG_WIDTH), static_cast<float>(SCREEN_HEIGHT)), inner });

	m_info.showAlien(&m_seekAlien);
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
			if (sf::Keyboard::Enter == currentEvent.key.code)
				m_info.activateButton();
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

	for(auto& e: m_entities)
		e->update(t_deltaTime);
}

//****************************************

void Game::render()
{
	m_window.clear();

	for (auto& e : m_entities)
		m_window.draw(*e);

	m_window.draw(m_debugArea);
	m_window.draw(m_info);

	m_window.display();
}
