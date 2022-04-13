#include "Bullet/CannonBall.hpp"
#include "Algorithms.hpp"
#include "DamageCircle/BuildingDamageCircle.hpp"
#include "DamageCircle/DamageCircles.hpp"

CannonBall::CannonBall(sf::Vector2f spawnPosition, sf::Vector2f aim_, double damage, double damageRadius, DamageCircles &damgeCircles_, Enemies &enemies) : damageCircles{ damgeCircles_ }, Bullet{ spawnPosition, aim_, damage, damageRadius }, enemies{ enemies } {
    speed = 0.01 * CELL_LENGTH;
}

void CannonBall::move_() {
    Bullet::move_();
    sf::Vector2f distance = Algorithms::calculateDistanceVector(getCenter(), getAimVector2f());
    if (abs(distance.x) < speed && abs(distance.y) < speed) {
        damageCircles.append(new BuildingDamageCircle(getAimVector2f(), damage, getDamageRadiusd(), enemies));
        deleted = true;
    }
}

