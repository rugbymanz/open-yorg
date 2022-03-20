#pragma once

#include <SFML/Graphics/CircleShape.hpp>

#include "Can/CanMove.hpp"
#include "Can/CanHaveHp.hpp"
#include "Can/CanDamage.hpp"
#include "Graphical.hpp"


class Enemy: public CanMove, public CanHaveHp, public CanDamage, public sf::CircleShape, public Graphical {
public:
    Enemy(const FieldCoord &spawnPosition);

    void goTo();
    void attack();

private:
    void draw();
    void update();
};