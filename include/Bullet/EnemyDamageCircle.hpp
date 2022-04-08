#pragma once

#include "Bullet/DamageCircle.hpp"

class Field;

class EnemyDamageCircle : public DamageCircle {
public:
	EnemyDamageCircle(FieldCoord aim, double damage, int damageRadius, Field &field);
};