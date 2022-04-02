#include "Bullet/Bullet.hpp"
#include "Algorithms.hpp"

// Bullet::Bullet(aim, damage): aim{aim}, damage{damage}{
//     Game::gameElements.ammunitions.add(*this)
//     movementAzimuth = Algorithms::calculateAzimuth(getCenter(), aim)
// }

// update(){
//     if(!aim.contains(getCenter())
//         move(movementAzimuth * speed, movementAzimuth * speed
//     else{
//         damage()
//         erase()
//     }
// }

// damage(){
//     foreach i in creatures
//         if(distance(i.getCenter(), getCenter()) < radius){
//             i.hp -= damage;
//         }
// }

// erase(){
//     erased = true;
// }

Bullet::Bullet(sf::Vector2f spawnPosition, FieldCoord aim) : CanDamage{ aim } {
    setMovementAzimuth(spawnPosition, Algorithms::mapFieldCoordToVector2fCentered(aim) );
}

void Bullet::draw(){
    
}

void Bullet::update() {
}