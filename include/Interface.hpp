#pragma once

#include "ValuesAndTypes.hpp"

class Field;

class Interface{
public:
    FieldCoord selectedCell;

    Interface(Field &field);
    void tick();
    void update();
    void selectCell(const FieldCoord &selection);

private:
    Field &field;
};