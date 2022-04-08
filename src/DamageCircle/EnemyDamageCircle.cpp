#include "DamageCircle/EnemyDamageCircle.hpp"
#include "Algorithms.hpp"
#include "Field/Field.hpp"
#include "Field/FieldCell.hpp"
#include "Building/Building.hpp"

EnemyDamageCircle::EnemyDamageCircle(FieldCoord aim, double damage, int damageRadius, Field &field) : DamageCircle(aim, damage, damageRadius * CELL_LENGTH / 2) {
	static_cast<Building &>(field.get(aim)).decreaseHp(damage);
}