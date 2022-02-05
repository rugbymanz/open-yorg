#pragma once

#include "Field/FieldCell.hpp"

class Resource: public FieldCell{
public:
    Resource(const FieldCoord &fieldCoord);
};