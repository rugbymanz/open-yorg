#pragma once

#include "Field/FieldCell.hpp"

class Resource: public FieldCell{
public:
    enum class Types{
        iron,
        wood,
        crystal,
        N,

        none
    } type = Types::none;
};