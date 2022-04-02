#include "Bullet/EnemyBullet.hpp"

EnemyBullet::EnemyBullet(sf::Vector2f spawnPosition, FieldCoord aim) : Bullet{ spawnPosition, aim } {
	speed = 0.01 * CELL_LENGTH;
};

