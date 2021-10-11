#ifndef MATH_UTILS_INCLUDE
#define MATH_UTILS_INCLUDE

#include <SFML/Graphics.hpp>
#include <cmath>

#define PI 3.14159263

static float getPositiveHeading(sf::Vector2f t_vec)
{
    return atan2f(t_vec.y, t_vec.x);
}

static float Deg2Rad(float t_deg)
{
    return static_cast<float>(t_deg * PI /180.0);
}

static float Rad2Deg(float t_rad)
{
    return static_cast<float>(t_rad * 180.0 / PI);
}

static float CrossProduct(const sf::Vector2f& v1,const sf::Vector2f& v2)
{
    return (v1.x * v2.y) - (v1.y * v2.x);
}

static float VectorSquaredDistance(const sf::Vector2f& v1)
{
    return (v1.x * v1.x) + (v1.y * v1.y);
}

static float VectorDistance(const sf::Vector2f& v1)
{
    return sqrtf(VectorSquaredDistance(v1));
}

static void UnitVec(sf::Vector2f& v1)
{
    float dis = VectorDistance(v1);
    if (dis != 0)
        v1 /= dis;
}

static sf::Vector2f getUnitVec(const sf::Vector2f& v1)
{
    float dis = VectorDistance(v1);
    if (dis != 0)
        return v1 / dis;
    return sf::Vector2f();
}

#endif