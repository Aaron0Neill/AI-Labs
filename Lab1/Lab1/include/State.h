#ifndef STATE_INCLUDE
#define STATE_INCLUDE

#include <SFML/Graphics.hpp>

class State
{
public:
    virtual void update(sf::Time t_dt) = 0;
private:
};
#endif