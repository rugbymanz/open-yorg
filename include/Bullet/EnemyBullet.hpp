#pragma once
#include "Bullet/Bullet.hpp"

class Field;

class EnemyBullet : public Bullet {
public:
	EnemyBullet(sf::Vector2f spawnPosition, FieldCoord aim, double damage, Field &field, double damageRadius);
protected:
	void move_()override;
private:
	Field &field;
};
