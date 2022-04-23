#include "Building/Building.hpp"

Building::Building(const FieldCoord &fieldCoord): FieldCell{fieldCoord}{
	isCompatibleWith[Compatibilities::enemy] = true;
	isDestructable = true;
	isEmpty = false;
	setHp(12);
}

void Building::update() {
	if (getHp() <= 0)
		deleted = true;
}