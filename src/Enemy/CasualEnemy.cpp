#include "Enemy/CasualEnemy.hpp"
#include "Enemy/Enemies.hpp"

CasualEnemy::CasualEnemy(const FieldCoord &spawnPosition, Enemies &enemies, PathSearchField &pathSearchField, Bullets &bullets, Field &field) : Enemy{ spawnPosition, pathSearchField, bullets, 4, field, 1 } {
	enemies.append(this);
	fireRate = 1;
	speed = 0.01 * CELL_LENGTH;
}