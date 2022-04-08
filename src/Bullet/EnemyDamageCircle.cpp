#include "Bullet/EnemyDamageCircle.hpp"
#include "Algorithms.hpp"

EnemyDamageCircle::EnemyDamageCircle(FieldCoord aim, double damage, int damageRadius, Field &field) : DamageCircle(aim, damage, damageRadius * CELL_LENGTH) {
	
}