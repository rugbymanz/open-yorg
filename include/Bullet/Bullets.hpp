#pragma once

#include <forward_list>

class Bullet;

class Bullets{
public:
    void tick();
    void append(Bullet *bullet);

private:
    std::forward_list<Bullet*> bullets;
};