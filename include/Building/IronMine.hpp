#pragma once

#include "Building/Mine.hpp"

class IronMine: public Mine{
public:
	IronMine(Field &field, const FieldCoord &fieldCoord, ResourceBalls &resourceBalls, Road &road);

private:
	void mine()override;
};