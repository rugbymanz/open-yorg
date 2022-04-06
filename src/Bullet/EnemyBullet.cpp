#include "Bullet/EnemyBullet.hpp"
#include "Algorithms.hpp"
#include "Building/Building.hpp"
#include "Field/Field.hpp"

EnemyBullet::EnemyBullet(sf::Vector2f spawnPosition, FieldCoord aim, double damage, Field &field, double damageRadius) : Bullet{ spawnPosition, aim, damage, damageRadius }, field{ field } {
	speed = 0.01 * CELL_LENGTH;
}

void EnemyBullet::move_(){
    Bullet::move_();
    sf::Vector2f distance = Algorithms::calculateDistanceVector(getCenter(), Algorithms::mapFieldCoordToVector2fCentered(aim));
    if (abs(distance.x) < speed && abs(distance.y) < speed) {
        static_cast<Building&>(field.get(aim)).decreaseHp(damage);
        deleted = true;
    }
}

