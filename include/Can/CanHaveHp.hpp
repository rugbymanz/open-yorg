#pragma once

#include "ValuesAndTypes.hpp"

class CanHaveHp{
public:
    double getHp() const;
    void setHp(double hp);
    void decreaseHp(const double hp);

private:
    double hp = NONE;
};