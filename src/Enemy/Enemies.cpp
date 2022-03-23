#include "Enemy/Enemies.hpp"
#include "Enemy/CasualEnemy.hpp"

Enemies::Enemies() {
}

Enemy *Enemies::append(Enemy *enemy) {
    enemies.push_front(enemy);
    return enemy;
}

void Enemies::tick(){
    // foreach i in creatures
    //     if(i.erased){
    //         erase(i)
    //     }
    //     i.tick()
}