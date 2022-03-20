#pragma once

#include "Resource/Resource.hpp"

class Crystal: public Resource{
public:
    Crystal(const FieldCoord &fieldCoord);
    void draw() override;
};