#pragma once

#include "Field/FieldCell.hpp"
#include "Can/CanHaveHp.hpp"
#include "ValuesAndTypes.hpp"

class Building: public FieldCell, public CanHaveHp{
public:
    enum class Types{
        base,
        N,

        none,
    } type = Types::none;

    double hp = ValuesAndTypes::none;

    Types getType() const;

private:
    void draw();
};