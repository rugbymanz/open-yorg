#pragma once

#include "ValuesAndTypes.hpp"

class Interface{
public:
    FieldCoord selectedCell;

    void tick();
    void update();
    void selectCell(const FieldCoord &selection);

private:
};