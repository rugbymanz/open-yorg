#include "Enemy/Enemy.hpp"
#include "Field/PathSearchField.hpp"
#include "Algorithms.hpp"

Enemy::Enemy(const FieldCoord &spawnPosition) : path{ PathSearchField::generatePath(spawnPosition) } {
    currentPosition = Algorithms::mapFieldCoordToVector2f(spawnPosition);
}

void Enemy::draw(){

}

void Enemy::update(){
    

    // moveSprite
}