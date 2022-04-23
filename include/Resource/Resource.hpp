#pragma once

#include "Field/FieldCell.hpp"
#include "ValuesAndTypes.hpp"

class Resource: public FieldCell{
public:
    Resource(const FieldCoord &fieldCoord);

    void update()override;
};