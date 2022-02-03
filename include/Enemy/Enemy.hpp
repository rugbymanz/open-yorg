#pragma once

#include <SFML/Graphics/CircleShape.hpp>

#include "Can/CanMove.hpp"
#include "Can/CanHaveHp.hpp"
#include "Can/CanDamage.hpp"
#include "Drawable.hpp"


class Enemy: public CanMove, public CanHaveHp, public CanDamage, public sf::CircleShape, public Drawable{
public:
    Enemy(const FieldCoord &spawnPosition);

    void goTo();
    void attack();

private:
    void draw();
    void update();
};