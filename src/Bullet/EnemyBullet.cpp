#include "Bullet/EnemyBullet.hpp"
#include "Algorithms.hpp"
#include "Building/Building.hpp"
#include "Field/Field.hpp"
#include "DamageCircle/EnemyDamageCircle.hpp"
#include "DamageCircle/DamageCircles.hpp"

EnemyBullet::EnemyBullet(sf::Vector2f spawnPosition, FieldCoord aim, double damage, Field &field, double damageRadius, DamageCircles &damgeCircles_) : damageCircles{ damgeCircles_ }, Bullet { spawnPosition, aim, damage, damageRadius }, field{ field } {
	speed = 0.01 * CELL_LENGTH;
}

void EnemyBullet::move_(){
    Bullet::move_();
    sf::Vector2f distance = Algorithms::calculateDistanceVector(getCenter(), Algorithms::mapFieldCoordToVector2fCentered(aim));
    if (abs(distance.x) < speed && abs(distance.y) < speed) {
        damageCircles.append(new EnemyDamageCircle(aim, damage, damageRadius, field));
        deleted = true;
    }
}

