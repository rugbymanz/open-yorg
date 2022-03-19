#pragma once

#include <vector>
#include <functional>

#include "ValuesAndTypes.hpp"
#include "Road.hpp"
#include "PathSearchField.hpp"
#include "ValuesAndTypes.hpp"
#include "FieldCell.hpp"

class Field{
public:
    static FieldCoord basePosition;
    Road road;
    PathSearchField pathSearchField;

    Field();
    void tick();
    void update();
    void draw();
    static void set(FieldCell *const fieldCell);
    static FieldCell &get(const FieldCoord &fieldCoord);
    ~Field();

private:
    static std::vector< std::vector<FieldCell*> > field;
};