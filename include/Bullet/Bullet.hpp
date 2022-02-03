#pragma once

#include <SFML/Graphics/CircleShape.hpp>

#include "Drawable.hpp"
#include "Can/CanMove.hpp"
#include "Can/CanDamage.hpp"

class Bullet: public sf::CircleShape, public Drawable, public CanMove, public CanDamage{
public:
    // void update();
    // void damage();
    // void erase();
    void draw();
};