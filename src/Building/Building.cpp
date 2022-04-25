#include "Building/Building.hpp"

Building::Building(const FieldCoord &fieldCoord, int connectionRadius): FieldCell{fieldCoord, connectionRadius}{
	isDestructable = true;
	isEmpty = false;
	setHp(12);
}

void Building::update() {
	if (getHp() <= 0)
		deleted = true;
}