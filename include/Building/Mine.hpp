#pragma once

#include "Building/Building.hpp"

class Field;

class Mine: public Building{
public:
    Mine(Field &field, const FieldCoord &fieldCoord);
private:
    void draw() override;
};