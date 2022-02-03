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
    FieldCoord basePosition = ValuesAndTypes::noneFieldCell;
    Road road;
    PathSearchField pathSearchField;

    Field();
    void tick();
    void update();
    void draw();
    void set(const FieldCoord &fieldCoord, const FieldCell &fieldCell);
    FieldCell& get(const FieldCoord &fieldCoord);
    std::vector<std::reference_wrapper<FieldCell> >& operator[] (const int index);

private:
    std::vector< std::vector<FieldCell*> > field;
};