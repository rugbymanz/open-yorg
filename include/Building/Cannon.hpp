#pragma once

#include "Building.hpp"
#include "Can/CanDamage.hpp"
#include "Can/CanStore.hpp"

class Cannon: public Building, public CanDamage, public CanStore{
public:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    void shootAim();
    void tick();
};