#include "Game.h"

Game::Game() :
	m_window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "AI Lab1"),
	m_player("Ronald mcDonald"),
	m_GLaDOS("GLaDOS"),
	m_clapTrap("CL4P-TP"),
	m_debugArea(sf::Quads),
	m_info(m_gameFont, &Game::addAlien, this)
{
	m_gameFont.loadFromFile("assets/calibri.ttf");

	m_GLaDOS.setPosition({ 300,300 });
	m_GLaDOS.setTarget(&m_player.getPosition());
	m_GLaDOS.setState(AiStates::WANDER);
	m_GLaDOS.setPlayerVelocity(&m_player.getVelocity());

	m_clapTrap.setTarget(&m_player.getPosition());
	m_clapTrap.setState(AiStates::SEEK);
	m_clapTrap.setPosition({ 100,100 });
	m_clapTrap.setPlayerVelocity(&m_player.getVelocity());

	m_aliens.push_back(&m_GLaDOS);
	m_aliens.push_back(&m_clapTrap);

	sf::Color inner = sf::Color(100, 100, 100, 100);
	sf::Color outer = sf::Color(100, 100, 100, 255);

	m_debugArea.append(sf::Vertex{ sf::Vector2f(static_cast<float>(SCREEN_WIDTH - DEBUG_WIDTH), 0.0f), inner });
	m_debugArea.append(sf::Vertex{ sf::Vector2f(static_cast<float>(SCREEN_WIDTH), 0.0f), outer });
	m_debugArea.append(sf::Vertex{ sf::Vector2f(static_cast<float>(SCREEN_WIDTH), static_cast<float>(SCREEN_HEIGHT)), outer });
	m_debugArea.append(sf::Vertex{ sf::Vector2f(static_cast<float>(SCREEN_WIDTH - DEBUG_WIDTH), static_cast<float>(SCREEN_HEIGHT)), inner });

	m_info.init();
	m_info.showAlien(&m_clapTrap);
}

//****************************************

Game::~Game()
{
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
		else if (sf::Event::MouseMoved == currentEvent.type)
		{
			m_info.updateButton(static_cast<sf::Vector2f>(sf::Mouse::getPosition(m_window)));
		}
		else if (sf::Event::MouseButtonPressed == currentEvent.type)
		{
			sf::Vector2f clickPos = static_cast<sf::Vector2f>(sf::Mouse::getPosition(m_window));

			m_info.clickButton(clickPos);

			for (auto& e : m_aliens)
			{
				if (e->getBody().getGlobalBounds().contains(clickPos))
				{
					m_info.showAlien(e);
					break;
				}
			}
		}
		else if (sf::Event::MouseButtonReleased == currentEvent.type)
		{
			m_info.releaseButton(static_cast<sf::Vector2f>(sf::Mouse::getPosition(m_window)));
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

	m_player.update(t_deltaTime);

	for(auto& e: m_aliens)
		e->update(t_deltaTime);
}

//****************************************

void Game::render()
{
	m_window.clear();

	m_window.draw(m_player);

	for (auto& e : m_aliens)
		m_window.draw(*e);

	m_window.draw(m_debugArea);
	m_window.draw(m_info);

	m_window.display();
}

//****************************************

void Game::addAlien()
{
	Alien* e = new Alien("Clone");
	e->setState(AiStates::PURSUE);
	e->setPosition({ static_cast<float>(rand() % (SCREEN_WIDTH - DEBUG_WIDTH)),
		static_cast<float>(rand() % SCREEN_HEIGHT) });
	e->setTarget(&m_player.getPosition());
	e->setPlayerVelocity(&m_player.getVelocity());
	m_aliens.push_back(e);
}
