#pragma once

#include "Can/CanHaveHp.hpp"
#include "Building/Building.hpp"

class Wall:	public Building{
public:
    Wall(const FieldCoord &fieldCoord);
	void draw()override;
};