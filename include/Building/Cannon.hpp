#pragma once

#include <SFML/Graphics/CircleShape.hpp>

#include "Building.hpp"
#include "Can/CanShoot.hpp"
#include "Can/CanStore.hpp"

class Enemies;
class Enemy;

class Cannon: public Building, public CanShoot, public CanStore{
public:
    Cannon(FieldCoord &fieldCoord, Enemies &enemies);
    void draw() override;
    void shootAim()override;
    void update()override;

private:
    Enemies &enemies;
    Enemy *aim = nullptr;
};