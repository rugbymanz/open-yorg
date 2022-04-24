#pragma once

#include "Building/Building.hpp"

class Transporter: public Building{
public:
	Transporter(const FieldCoord &fieldCoord);
	void draw()override;
};