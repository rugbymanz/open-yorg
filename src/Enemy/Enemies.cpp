#include "Enemy/Enemies.hpp"
#include "Enemy/Enemy.hpp"

Enemies::Enemies() {
}

Enemy *Enemies::append(Enemy *enemy) {
    enemies.push_front(enemy);
    return enemy;
}

void Enemies::update() {
    for (auto &el : enemies) 
        el->update();
}

void Enemies::draw() {
    for (auto &el : enemies)
        el->draw();
}