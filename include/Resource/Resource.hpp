#pragma once

#include "Field/FieldCell.hpp"
#include "ValuesAndTypes.hpp"

class Resource: public FieldCell{
public:
    ResourceType type{ ResourceType::none };

    Resource(const FieldCoord &fieldCoord);

    void update()override;
};