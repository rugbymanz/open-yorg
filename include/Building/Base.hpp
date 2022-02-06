#pragma once

#include "Building/Building.hpp"
#include "Can/CanStore.hpp"

class Base: public Building, public CanStore{
public:
    Base(const FieldCoord &fieldCoord);

    void draw()override;
};