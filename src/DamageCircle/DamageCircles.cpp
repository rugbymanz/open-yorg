#include "DamageCircle/DamageCircles.hpp"
#include "DamageCircle/DamageCircle.hpp"

void DamageCircles::append(DamageCircle *damageCircle) {
    damageCircles.push_front(damageCircle);
}

void DamageCircles::tick() {
    for (auto &el : damageCircles) {
        if (el->deleted) {
            delete el;
            el = nullptr;
            continue;
        }
        el->update();
        el->draw();
    }

    damageCircles.remove(nullptr);
}