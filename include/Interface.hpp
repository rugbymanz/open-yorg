#pragma once

#include "ValuesAndTypes.hpp"

class Interface{
public:
    static FieldCoord selectedCell;

    void tick();
    void update();
    static void selectCell(const FieldCoord &selection);

private:
};