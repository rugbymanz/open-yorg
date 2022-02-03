#pragma once

#include <SFML/System/Clock.hpp>
#include <SFML/System/Vector2.hpp>

#include "ValuesAndTypes.hpp"

class CanDamage{
public:
    double damageRadius = ValuesAndTypes::none;
    double fireRate = ValuesAndTypes::none;
    sf::Clock clock;
    double damage = ValuesAndTypes::none;
    sf::Vector2f aim = ValuesAndTypes::noneVector2f;

    virtual void update();
    virtual void findAim();
    void shootAim();
    bool isTimeToShoot();
};