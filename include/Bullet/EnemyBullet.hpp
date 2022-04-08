#pragma once
#include "Bullet/Bullet.hpp"

class Field;
class DamageCircles;

class EnemyBullet : public Bullet {
public:
	EnemyBullet(sf::Vector2f spawnPosition, FieldCoord aim, double damage, Field &field, double damageRadius, DamageCircles &damgeCircles);
protected:
	void move_()override;
private:
	Field &field;
	DamageCircles &damageCircles;
};
