#include "Enemy/CasualEnemy.hpp"
#include "Enemy/Enemies.hpp"

CasualEnemy::CasualEnemy(const FieldCoord &spawnPosition, Enemies &enemies, PathSearchField &pathSearchField): Enemy(spawnPosition, pathSearchField) {
	enemies.append(this);
}