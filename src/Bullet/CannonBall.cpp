#include "Bullet/CannonBall.hpp"
#include "Algorithms.hpp"
#include "DamageCircle/BuildingDamageCircle.hpp"
#include "DamageCircle/DamageCircles.hpp"

EnemyBullet::EnemyBullet(sf::Vector2f spawnPosition, FieldCoord aim, double damage, Field &field, int damageRadius, DamageCircles &damgeCircles_) : damageCircles{ damgeCircles_ }, Bullet{ spawnPosition, aim, damage, damageRadius }, field{ field } {
    speed = 0.01 * CELL_LENGTH;
}

void EnemyBullet::move_() {
    Bullet::move_();
    sf::Vector2f distance = Algorithms::calculateDistanceVector(getCenter(), getAimVector2f());
    if (abs(distance.x) < speed && abs(distance.y) < speed) {
        damageCircles.append(new EnemyDamageCircle(getAimFieldCoord(), damage, getDamageRadiusi(), field));
        deleted = true;
    }
}

