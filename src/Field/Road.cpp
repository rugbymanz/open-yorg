#include "Field/Road.hpp"

void Road::tick(){
    update();
}
void Road::update(){
}

FieldCoord Road::findPath(const FieldCoord &source, const FieldCoord &destination){
    return ValuesAndTypes::noneFieldCell;
}