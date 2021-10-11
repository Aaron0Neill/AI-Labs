#ifndef ALIEN_H
#define ALIEN_H

#include "Entity.h"
#include <functional>
#include "StateInclude.h"
#include <unordered_map>

enum class AiStates{
    NONE = -1,
    WANDER,
    SEEK,
    ARRIVE,
    FLEE,
    PURSUE
};

class Alien : public Entity
{
public:
    Alien(std::string const& t_name);
    ~Alien();

    virtual void setState(AiStates const& t_state);

    virtual void update(sf::Time t_dt)override;

    virtual void setTarget(sf::Vector2f* t_target);

    virtual void setPosition(sf::Vector2f t_pos);

    virtual const std::string& getState();
    float getHeading(){
        return atan2f(m_velocity.y, m_velocity.x);
    }

private:
    friend class State;
    friend class WanderState;
    friend class SeekState;
    friend class ArriveState;

    AiStates m_currentState;

    State* m_stateMovement;

    sf::Vector2f* m_target;

    std::unordered_map<AiStates, std::string> m_mapping;
};
#endif