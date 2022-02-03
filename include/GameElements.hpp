#pragma once

#include "Field/Field.hpp"
#include "Enemy/Enemies.hpp"
#include "Resource/ResourceBalls.hpp"
#include "Bullet/Bullets.hpp"

class GameElements{
public:
    Field field;
    Enemies enemies;
    ResourceBalls resourceBalls;
    Bullets bullets;

    void tick();
};