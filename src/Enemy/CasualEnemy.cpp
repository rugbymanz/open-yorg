#include "Enemy/CasualEnemy.hpp"
#include "Enemy/Enemies.hpp"

CasualEnemy::CasualEnemy(const FieldCoord &spawnPosition): Enemy(spawnPosition) {
	Enemies::enemies.push_front(this);
}