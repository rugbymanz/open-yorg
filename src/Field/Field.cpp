#include <time.h>

#include "Field/Field.hpp"
#include "Field/EmptyFieldCell.hpp"

FieldCoord Field::basePosition = NONE_FIELD_CELL;
std::vector< std::vector<FieldCell *> > Field::field;

Field::Field(){
    srand(time(0));

    field.resize(FIELD_LENGTH);

    for(auto row = field.begin(); row < field.end(); row++){
        row->resize(FIELD_WIDTH);
        for(auto col = row->begin(); col < row->end(); col++){
            *col = new EmptyFieldCell({ int(row - field.begin()), int(col - row->begin()) });
            // cellType = rand();
            // if(cellType != FieldCellType::none)
            //     placeNew(FieldCell(row, column), toResource(cellType))
            // else{
            //     placeNew(FieldCell(row, column), None())
            // }
        }
    }
}

void Field::tick(){
    update();
    draw();
}

void Field::update(){
}

void Field::draw(){
    for(auto &row: field)
        for(auto &col: row)
            col->draw();
}

void Field::set(FieldCell *const fieldCell){
    const FieldCoord &fieldCoord = fieldCell->getCoord();
    delete field[fieldCoord.x][fieldCoord.y];
    field[fieldCoord.x][fieldCoord.y] = fieldCell;
    // field[fieldCoord.x][fieldCoord.y].setCoord(fieldCoord)
    // switch(fieldCell.type){
    // case FieldCellType::building:
    //     buildingType = static_cast<Building>(fieldCell) . type
    //     switch(buildingType){
    //     case BuildingType::base:
    //         basePosition = fieldCoord
    //         break;
    //     }
    //     break;
    // }
    // pathSearchField.placeNew(fieldCoord, fieldCell)
    // road.placeNew(fieldCoord)
}

FieldCell& Field::get(const FieldCoord &fieldCoord){
    return *field[fieldCoord.x][fieldCoord.y];
}

Field::~Field(){
    for(auto &row: field)
        for(auto &col: row)
            delete col;
}