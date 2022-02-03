#include "Field/Field.hpp"

Field::Field(){
    srand(time(0));

    field.resize(ValuesAndTypes::Field::fieldLength);

    for(auto iterator1 = field.begin(); iterator1 < field.end(); iterator1++){
        iterator1->resize(ValuesAndTypes::Field::fieldWidth);
        for(auto iterator2 = iterator1->begin(); iterator2 < iterator1->end(); iterator2++){
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
    // foreach cell
    //     cell.draw()
}

void Field::set(const FieldCoord& fieldCoord, const FieldCell& fieldCell){
    // field[fieldCoord.x][fieldCoord.y] = fieldCell
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