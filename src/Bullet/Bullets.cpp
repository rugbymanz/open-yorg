#include "Bullet/Bullets.hpp"

void Bullets::append(const Bullet &bullet){
    bullets.push_front(bullet);
}

void Bullets::tick(){
    // foreach i in ammunitions{
    //     if(i.erased){
    //         erase(i)
    //     }
    //     i.tick()
    // }
}