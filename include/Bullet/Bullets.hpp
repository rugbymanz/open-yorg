#pragma once

#include <forward_list>

#include "Bullet.hpp"

class Bullets{
public:
    void tick();
    static void append(const Bullet &bullet);

private:
    static std::forward_list<Bullet> bullets;
};