#pragma once

#include <list>

class Bullet;

class Bullets{
public:
    void tick();
    void append(Bullet *bullet);

private:
    std::list<Bullet*> bullets;
};