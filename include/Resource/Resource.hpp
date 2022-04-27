#pragma once

#include "Field/FieldCell.hpp"
#include "ValuesAndTypes.hpp"

class Resource: public FieldCell{
public:
    ResourceType resourceType{ ResourceType::none };

    Resource(const FieldCoord &fieldCoord);

    void update()override;
};