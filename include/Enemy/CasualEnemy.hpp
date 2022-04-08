#pragma once

#include "Enemy/Enemy.hpp"

class Enemies;
class Field;
class DamageCircles;

class CasualEnemy: public Enemy{
public:
	CasualEnemy(const FieldCoord &spawnPosition, Enemies &enemies, PathSearchField &pathSearchField, Bullets &bullets, Field &field, DamageCircles &damageCircles);
};