#pragma once

#include <SFML/System/Clock.hpp>
#include <SFML/System/Vector2.hpp>

#include "ValuesAndTypes.hpp"

class CanDamage{
public:
    double damageRadius = NONE;
    double fireRate = NONE;
    sf::Clock clock;
    double damage = NONE;
    FieldCoord aim = NONE_FIELD_CELL;

    virtual void update();
    virtual void findAim();
    void shootAim();
    bool isTimeToShoot();
};