#pragma once

#include <SFML/Graphics.hpp>

static float SquaredMagnitude(sf::Vector2f const& t_vec) { return t_vec.x * t_vec.x + t_vec.y * t_vec.y; }