#pragma once

#include "Enemy/Enemy.hpp"

class CasualEnemy: public Enemy{
public:
	CasualEnemy(const FieldCoord &spawnPosition);
};