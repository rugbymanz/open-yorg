#pragma once

#include <SFML/System/Vector2.hpp>

class Drawable{
public:
    sf::Vector2f getCenter();
    // virtual int getType() = 0;
};