#include "Bullet/Bullets.hpp"
#include "Bullet/Bullet.hpp"

void Bullets::append(Bullet *bullet){
    bullets.push_front(bullet);
}

void Bullets::tick(){
    for (auto &el : bullets) {
        if (el->deleted) {
            delete el;
            el = nullptr;
            continue;
        }
        el->update();
        el->draw();
    }

    bullets.remove(nullptr);
}