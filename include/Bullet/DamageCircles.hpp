#pragma once

#include <list>

class DamageCircle;

class DamageCircles {
public:
    void tick();
    void append(DamageCircle *damageCircle);

private:
    std::list<DamageCircle *> damageCircles;
};