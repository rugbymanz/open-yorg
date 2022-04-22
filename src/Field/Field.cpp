#include <time.h>

#include "Field/Field.hpp"
#include "Field/EmptyFieldCell.hpp"

Field::Field() : pathSearchField{*this}, road(*this) {
    srand(time(0));

    field.resize(FIELD_LENGTH);

    for(auto col = field.begin(); col < field.end(); col++){
        col->resize(FIELD_WIDTH);
        for(auto row = col->begin(); row < col->end(); row++){
            *row = new EmptyFieldCell({ int(col - field.begin()), int(row - col->begin()) });
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
    pathSearchField.update();
    road.update();
    draw();
}

void Field::update(){
    for (auto &row : field)
        for (auto &col : row) {
            if (col->deleted) {
                FieldCoord fieldCoord = col->getCoord();
                set(new EmptyFieldCell{ fieldCoord });
            }
            else
                col->update();
        }
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