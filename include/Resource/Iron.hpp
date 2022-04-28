#pragma once

#include "Resource/Resource.hpp"

class Iron: public Resource{
public:
    Iron(const FieldCoord &fieldCoord);
    void draw() override;
};