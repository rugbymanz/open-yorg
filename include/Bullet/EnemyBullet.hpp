#pragma once
#include "Bullet/Bullet.hpp"

class EnemyBullet : public Bullet {
public:
	EnemyBullet(sf::Vector2f spawnPosition, FieldCoord aim);
};
