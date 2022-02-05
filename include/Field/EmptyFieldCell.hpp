#pragma once

#include "Field/FieldCell.hpp"

class EmptyFieldCell: public FieldCell{
public:
    EmptyFieldCell(const FieldCoord &fieldCoord);
    void draw()override;
};