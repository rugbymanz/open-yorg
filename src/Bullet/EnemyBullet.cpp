#include "Bullet/EnemyBullet.hpp"
#include "Algorithms.hpp"
#include "Building/Building.hpp"

EnemyBullet::EnemyBullet(sf::Vector2f spawnPosition, FieldCoord aim, Building *aimBuilding, double damage) : Bullet{ spawnPosition, aim, damage }, aimBuilding{aimBuilding} {
	speed = 0.01 * CELL_LENGTH;
};

void EnemyBullet::move_(){
    Bullet::move_();
    sf::Vector2f distance = Algorithms::calculateDistanceVector(getCenter(), Algorithms::mapFieldCoordToVector2fCentered(aim));
    if (abs(distance.x) < speed && abs(distance.y) < speed) {
        aimBuilding->decreaseHp(damage);
        deleted = true;
    }
}

