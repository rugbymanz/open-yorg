#pragma once

#include "Building/Mine.hpp"

class CrystalMine: public Mine{
public:
	CrystalMine(Field &field, const FieldCoord &fieldCoord, ResourceBalls &resourceBalls, Road &road);
};