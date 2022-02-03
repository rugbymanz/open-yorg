#pragma once

#include <forward_list>

#include "Bullet.hpp"

class Bullets{
public:
    void tick();
    void append(const Bullet &bullet);

private:
    std::forward_list<Bullet> bullets;
};