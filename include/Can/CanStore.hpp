#pragma once

#include "Building/Building.hpp"
#include "ValuesAndTypes.hpp"

class CanStore: public Building{
public:
    CanStore(const FieldCoord &fieldCoord);
    double storage = 0;
};