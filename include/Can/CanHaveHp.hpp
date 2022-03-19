#pragma once

#include "ValuesAndTypes.hpp"

class CanHaveHp{
public:
    double getHp() const;
    void setHp(double hp);
    void varyHp();

private:
    double hp = NONE;
};