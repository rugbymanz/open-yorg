#include "Can/CanDamage.hpp"

void CanDamage::update(){
    if(isTimeToShoot()){
        findAim();
        shootAim();
    }
}

void CanDamage::findAim(){
    // enimy;
    // minDistance
    // foreach i in creatures
    //     if(distance = Algorithms::distance( getPosition(), i.getPosition() ); distance < radius){

    //     }

}

void CanDamage::shootAim(){
    // clock.reset();
}

bool CanDamage::isTimeToShoot(){
    // return Clock::seconds(fireRate) < clock
}