#include "Interface.hpp"
#include "Game.hpp"
#include "ValuesAndTypes.hpp"

FieldCoord Interface::selectedCell = NONE_FIELD_CELL;

void Interface::tick(){
    update();
}

void Interface::update(){
    
}

void Interface::selectCell(const FieldCoord &selection){
    if(selectedCell != NONE_FIELD_CELL)
        Field::get(selectedCell).setOutlineColor(UNSELECTED);
    Field::get(selection).setOutlineColor(SELECTED);
    selectedCell = selection;
}