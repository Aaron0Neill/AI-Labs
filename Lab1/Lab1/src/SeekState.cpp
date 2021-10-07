#include "SeekState.h"

SeekState::SeekState(sf::Vector2f* t_target) : 
    m_target(&(*t_target))
{

}

SeekState::~SeekState()
{

}

void SeekState::onEnter()
{
    std::cout << "Entering Seek State\n";
}

void SeekState::update(sf::Time t_dt)
{
}

void SeekState::onExit()
{
    std::cout << "Exiting Seek State\n";
}