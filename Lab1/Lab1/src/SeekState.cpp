#include "SeekState.h"

SeekState::SeekState(Alien* t_alien) : 
    State(t_alien)
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