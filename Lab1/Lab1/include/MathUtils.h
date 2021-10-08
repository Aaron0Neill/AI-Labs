#ifndef MATH_UTILS_INCLUDE
#define MATH_UTILS_INCLUDE

#include <SFML/Graphics.hpp>
#include <cmath>

#define PI 3.14159263

static float getHeading(sf::Vector2f t_vec)
{
    return atan2f(t_vec.y, t_vec.x);
}

static float Deg2Rad(float t_deg)
{
    return t_deg * PI /180.0;
}

static float Rad2Deg(float t_rad)
{
    return t_rad * 180.0 / PI;
}

#endif