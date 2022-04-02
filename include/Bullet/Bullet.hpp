#pragma once

#include <SFML/Graphics/CircleShape.hpp>

#include "Graphical.hpp"
#include "Can/CanMove.hpp"
#include "Can/CanDamage.hpp"

class Bullet: public sf::CircleShape, public Graphical, public CanMove, public CanDamage{
public:
    Bullet(sf::Vector2f spawnPosition, FieldCoord aim);
    // void update();
    // void damage();
    // void erase();
    void draw() override;
    void update()override;
};