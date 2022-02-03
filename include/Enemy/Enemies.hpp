#pragma once

#include <forward_list>

#include "Enemy/Enemy.hpp"

class Enemies{
public:
    std::forward_list<Enemy> enemies;

    void tick();
};