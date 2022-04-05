#include "Building/Building.hpp"

Building::Building(const FieldCoord &fieldCoord): FieldCell{fieldCoord}{
	isDestructable = true;
	isEmpty = false;
}