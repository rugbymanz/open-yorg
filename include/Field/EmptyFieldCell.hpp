#pragma once

#include "Field/FieldCell.hpp"

class EmptyFieldCell: public FieldCell{
public:
    EmptyFieldCell();
    void draw()override;
};